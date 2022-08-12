struct TreeNode * lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
    int rootVal = root->val, pVal = p->val, qVal = q->val;
    
    if (pVal == rootVal || qVal == rootVal) {
        return root;
    } else if (pVal < rootVal && qVal > rootVal) {
        return root;
    } else if (pVal > rootVal && qVal < rootVal) {
        return root;
    } else if (pVal < rootVal && qVal < rootVal) {
        return lowestCommonAncestor(root->left, p, q);
    }
    return lowestCommonAncestor(root->right, p, q);
}
