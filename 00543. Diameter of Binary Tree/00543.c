int dfs(struct TreeNode *root, int *max) {
    int l = 0, r = 0;
    
    if (root->left != NULL) {
        l = dfs(root->left, max);
    }
    
    if (root->right != NULL) {
        r = dfs(root->right, max);
    }
    
    if (*max < l + r) {
        *max = l + r;
    }
    
    return (l > r) ? l + 1 : r + 1;
}

int diameterOfBinaryTree(struct TreeNode *root) {
    int max = 0;
    
    dfs(root, &max);
    
    return max;
}
