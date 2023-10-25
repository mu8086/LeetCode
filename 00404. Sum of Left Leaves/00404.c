// https://leetcode.com/problems/sum-of-left-leaves

void helper(struct TreeNode *node, bool isLeft, int *sum) {
    if (node == NULL) {
        return;
    }

    if (isLeft && node->left == NULL && node->right == NULL) {
        *sum += node->val;
        return;
    }

    helper(node->left, true, sum);
    helper(node->right, false, sum);
}

int sumOfLeftLeaves(struct TreeNode *root) {
    int sum = 0;
    helper(root, false, &sum);
    return sum;
}
