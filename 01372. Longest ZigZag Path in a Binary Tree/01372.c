// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree

#define L 1
#define R 2

int longest;

void helper(struct TreeNode *root, int from, int count) {
    if (root == NULL) {
        if (longest < count) {
            longest = count;
        }
        return;
    }
    
    if (from == L) {
        helper(root->left, L, 0);
        helper(root->right, R, count+1);
    } else {
        helper(root->left, L, count+1);
        helper(root->right, R, 0);
    }
}

int longestZigZag(struct TreeNode *root) {
    int ans;

    helper(root->left, L, 0);
    helper(root->right, R, 0);
    
    ans = longest;
    longest = 0;
    return ans;
}
