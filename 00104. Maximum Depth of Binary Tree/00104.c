// https://leetcode.com/problems/maximum-depth-of-binary-tree

int maxDepth(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    return fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
}
