int traversal(struct TreeNode *root, int bitmap) {
    if (root == NULL) {
        return 0;
    } else {
        // use bitmap to record which val is odd frequency
        bitmap ^= (1 << root->val);
        
        if (root->left == NULL && root->right == NULL) {
            // odd frequency in the bitmap, must be 0 or 1 count to form a Pseudo-Palindromic Paths
            return (bitmap == 0 || ((bitmap & (bitmap-1)) == 0)) ? 1 : 0;
        }
    }
    
    return traversal(root->left, bitmap) + traversal(root->right, bitmap);
}

int pseudoPalindromicPaths (struct TreeNode *root) {
    return traversal(root, 0);
}
