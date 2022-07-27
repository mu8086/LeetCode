void helper(struct TreeNode *root, struct TreeNode **leftmost) {
    if (root != NULL) {
        if (*leftmost == NULL) {
            *leftmost = root;
        } else {
            (*leftmost)->left = root;
            *leftmost = root;
        }

        helper(root->left, leftmost);
        helper(root->right, leftmost);
    }
}

void flatten(struct TreeNode *root) {
    struct TreeNode *leftmost = NULL;

    // chained in left pointer
    helper(root, &leftmost);

    // chained in right pointer
    while (root != NULL) {
        root->right = root->left;
        root->left = NULL;
        root = root->right;
    }
}
