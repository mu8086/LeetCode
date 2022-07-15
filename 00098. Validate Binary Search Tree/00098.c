#define MAX_SIZE    10000

void inorder(struct TreeNode *root, int nums[], int *index) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left, nums, index);
    nums[++(*index)] = root->val;
    inorder(root->right, nums, index);
}

bool verify(int nums[], int lastIndex) {
    for (int i = 1; i <= lastIndex; ++i) {
        if (nums[i-1] >= nums[i]) {
            return false;
        }
    }
    return true;
}

bool isValidBST(struct TreeNode *root){
    static int nums[MAX_SIZE];
    static int index, size = sizeof(int) * MAX_SIZE;
    index = -1;
    memset(nums, 0, size);
    
    inorder(root, nums, &index);
    
    return verify(nums, index);
}
