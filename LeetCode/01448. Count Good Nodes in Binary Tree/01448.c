void helper(struct TreeNode *root, int max, int *count) {
    if (root != NULL) {
        if (max <= root->val) {
            max = root->val;
            ++(*count);
        }
        
        helper(root->left, max, count);
        helper(root->right, max, count);
    }
}

int goodNodes(struct TreeNode *root) {
    int count = 0;
    
    helper(root, INT_MIN, &count);
    
    return count;
}
