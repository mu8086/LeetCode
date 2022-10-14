// https://leetcode.com/problems/maximum-depth-of-binary-tree

int maxDepth(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    int l = maxDepth(root->left), r = maxDepth(root->right);

    return fmax(l, r) + 1;
}
