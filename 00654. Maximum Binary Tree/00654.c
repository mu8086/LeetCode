struct TreeNode * insert(struct TreeNode * root, int val) {
    if (root == NULL) {
        struct TreeNode *node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        *node = (struct TreeNode){ .val = val, .left = NULL, .right = NULL };
        root = node;
    } else if (val > root->val) {
        struct TreeNode *node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        *node = *root;
        *root = (struct TreeNode){ .val = val, .left = node, .right = NULL };
    } else {
        root->right = insert(root->right, val);
    }
    
    return root;
}

struct TreeNode * constructMaximumBinaryTree(int *nums, int numsSize) {
    struct TreeNode *root = NULL;
    
    for (int i = 0; i < numsSize; ++i) {
        root = insert(root, nums[i]);
    }
    
    return root;
}
