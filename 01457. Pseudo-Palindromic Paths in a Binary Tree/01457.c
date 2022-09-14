#define MAX_SIZE    10

void traversal(struct TreeNode *root, int map[], int odd_count, int *ans) {
    if (root != NULL) {
        ++(map[root->val]);
        odd_count += (map[root->val] % 2 == 1) ? 1 : -1;
        
        if (root->left != NULL || root->right != NULL) {
            traversal(root->left,  map, odd_count, ans);
            traversal(root->right, map, odd_count, ans);
        } else {
            if (odd_count <= 1) {
                ++(*ans);
            }
        }
        
        --(map[root->val]);
        // no need to do this, because the odd_count of parent is correct for itself
        // odd_count += (map[root->val] % 2 == 1) ? 1 : -1;
    }
}

int pseudoPalindromicPaths (struct TreeNode *root) {
    int ans = 0, map[MAX_SIZE] = {};
    
    traversal(root, map, 0, &ans);
    
    return ans;
}
