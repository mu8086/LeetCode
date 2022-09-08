void inorder(int *arr, int *index, struct TreeNode *root) {
    if (root != NULL) {
        inorder(arr, index, root->left);

        arr[(*index)++] = root->val;

        inorder(arr, index, root->right);
    }
}

int * inorderTraversal(struct TreeNode *root, int *returnSize) {
    *returnSize = 0;
    
    if (root != NULL) {
        int *ret = (int *) malloc(sizeof(int) * 100);
    
        inorder(ret, returnSize, root);
        
        return ret;
    }
    
    return NULL;
}
