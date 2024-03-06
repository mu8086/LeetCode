struct TreeNode * newNode(int val) {
    struct TreeNode *node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    *node = (struct TreeNode){ .val = val, .left = NULL, .right = NULL };
    return node;
}

struct TreeNode * sortedArrayToBST(int *nums, int numsSize) {
    int rootIndex = numsSize/2;
    struct TreeNode *root = newNode(nums[rootIndex]);
    
    if (numsSize > 1) {
        root->left = sortedArrayToBST(nums, rootIndex);
        if (numsSize > 2) {
            root->right = sortedArrayToBST(nums+rootIndex+1, numsSize-1-rootIndex);
        }
    }
    
    return root;
}
