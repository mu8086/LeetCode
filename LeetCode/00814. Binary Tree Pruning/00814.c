bool has1Descendant (struct TreeNode *root) {
    if (root != NULL) {
        bool l = has1Descendant(root->left);
        bool r = has1Descendant(root->right);
        
        if (l == false && root->left != NULL) {
            free(root->left);
            root->left = NULL;
        }
        
        if (r == false && root->right != NULL) {
            free(root->right);
            root->right = NULL;
        }
        
        if (root->val == 1) {
            return true;
        }
        
        return l || r;
    }
    
    return false;
}

struct TreeNode * pruneTree(struct TreeNode * root) {
    if (has1Descendant(root) == false) {
        free(root);
        root = NULL;
    }
    
    return root;
}
