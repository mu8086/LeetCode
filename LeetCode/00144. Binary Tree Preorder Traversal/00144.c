// https://leetcode.com/problems/binary-tree-preorder-traversal

#define MAX_SIZE 101

void preorder(struct TreeNode *root, int nums[MAX_SIZE], int *idx) {
    if (root == NULL) {
        return;
    }

    nums[(*idx)++] = root->val;
    preorder(root->left, nums, idx);
    preorder(root->right, nums, idx);
}

int * preorderTraversal(struct TreeNode *root, int *returnSize) {
    int nums[MAX_SIZE] = {};

    *returnSize = 0;

    if (root == NULL) {
        return NULL;
    }

    preorder(root, nums, returnSize);

    int *ans = (int *) malloc(sizeof(int) * *returnSize);
    memcpy(ans, nums, sizeof(int) * *returnSize);

    return ans;
}
