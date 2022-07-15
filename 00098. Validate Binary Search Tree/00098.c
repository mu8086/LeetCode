bool helper(struct TreeNode *root, struct TreeNode *min, struct TreeNode *max) {
    if (root == NULL) {
        return true;
    } else if ((min != NULL && root->val <= min->val) || (max != NULL && root->val >= max->val)) {
        return false;
    }
    return helper(root->left, min, root) && helper(root->right, root, max);
}

bool isValidBST(struct TreeNode *root) {
    return helper(root, NULL, NULL);
}
