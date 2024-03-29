struct TreeNode * lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
    if (root == NULL || p == root || q == root) {
        return root;
    }
    
    struct TreeNode *left  = lowestCommonAncestor(root->left,  p, q);
    struct TreeNode *right = lowestCommonAncestor(root->right, p, q);
    
    if (left == NULL) {
        return right;
    } else if (right == NULL) {
        return left;
    }
    return root;
}
