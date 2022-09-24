bool isLeaf(struct TreeNode *root) {
    return root != NULL && root->left == NULL && root->right == NULL;
}

void traversal(struct TreeNode *root, int *prefixNum, int prefixIdx, int prefixSum, int targetSum, int **ret, int *returnSize, int *returnColumnSizes) {
    if (root == NULL) {
        return;
    }

    prefixNum[prefixIdx]     = root->val;
    prefixSum               += root->val;

    if (isLeaf(root)) {
        if (prefixSum == targetSum) {
            ret[*returnSize] = (int *) malloc(sizeof(int) * (prefixIdx + 1));
            memcpy(ret[*returnSize], prefixNum, sizeof(int) * (prefixIdx + 1));
            returnColumnSizes[*returnSize] = prefixIdx + 1;
            ++(*returnSize);
        }
    } else {
        traversal(root->left,  prefixNum, prefixIdx+1, prefixSum, targetSum, ret, returnSize, returnColumnSizes);
        traversal(root->right, prefixNum, prefixIdx+1, prefixSum, targetSum, ret, returnSize, returnColumnSizes);
    }
}

int countLeaf(struct TreeNode *root, int depth, int *maxDepth) {
    int l = 0, r = 0;

    if (root != NULL) {
        l = countLeaf(root->left, depth+1, maxDepth);
        r = countLeaf(root->right, depth+1, maxDepth);

        if (*maxDepth < depth) {
            *maxDepth = depth;
        }

        if (l+r == 0) {
            return 1;
        }
    }

    return l+r;
}

int ** pathSum(struct TreeNode *root, int targetSum, int *returnSize, int **returnColumnSizes) {
    int maxDepth = 0;
    int maxRetSize = countLeaf(root, 1, &maxDepth);

    int prefixIdx = 0;
    int *prefixNum = (int *) malloc(sizeof(int) * maxDepth);
    //memset(prefixNum, 0, sizeof(int) * maxDepth);

    int ** ret = (int **) malloc(sizeof(int **) * maxRetSize);
    *returnColumnSizes = (int *) malloc(sizeof(int) * maxRetSize);
    *returnSize = 0;


    traversal(root, prefixNum, prefixIdx, 0, targetSum, ret, returnSize, *returnColumnSizes);


    if (*returnSize == 0) {
        if (maxRetSize > 0) {
            free(ret);
            free(*returnColumnSizes);
        }

        ret = NULL;
    }

    return ret;
}
