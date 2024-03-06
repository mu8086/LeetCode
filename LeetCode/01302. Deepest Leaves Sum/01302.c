void getDeepestLeavesSum(struct TreeNode* root, int level, int* sum, int* max_level) {
    if (*max_level < level) {
        *max_level = level;
        *sum = root->val;
    } else if (*max_level == level) {
        *sum += root->val;
    }
        
    if (root->left != NULL) {
        getDeepestLeavesSum(root->left, level+1, sum, max_level);
    }
    if (root->right != NULL) {
        getDeepestLeavesSum(root->right, level+1, sum, max_level);
    }
}

int deepestLeavesSum(struct TreeNode* root){
    int sum = 0, max_level = -1;
    
    if (root != NULL) {
        getDeepestLeavesSum(root, 0, &sum, &max_level);
    }
    
    return sum;
}
