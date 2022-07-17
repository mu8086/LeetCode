bool helper(struct TreeNode *lTree, struct TreeNode *rTree) {
    if (lTree == NULL && rTree == NULL) {
        return true;
    } else if (lTree == NULL || rTree == NULL || lTree->val != rTree->val) {
        return false;
    }
    return helper(lTree->left, rTree->right) && helper(lTree->right, rTree->left);
}

bool isSymmetric(struct TreeNode *root) {
    return helper(root->left, root->right);
}
