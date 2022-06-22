#define INVALID_VAL -1

int _kth(struct TreeNode *root, int k, int *counter) {
    int l = INVALID_VAL, r = INVALID_VAL;
    
    if (root != NULL && *counter != k) {
        l = _kth(root->left, k, counter);
        if (++(*counter) == k) {
            return root->val;
        }
        r = _kth(root->right, k, counter);
    }

    return (l != INVALID_VAL) ? l : r;
}

int kthSmallest(struct TreeNode *root, int k) {
    int counter = 0;
    return _kth(root, k, &counter);
}
