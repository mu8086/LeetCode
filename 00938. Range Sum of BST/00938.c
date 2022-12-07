// https://leetcode.com/problems/range-sum-of-bst

int rangeSumBST(struct TreeNode* root, int low, int high){
    if (root == NULL) {
        return 0;
    }

    int l = 0, r = 0, val = root->val;

    if (val < low) {
        r = rangeSumBST(root->right, low, high);
        val = 0;
    } else if (low <= val && val <= high) {
        l = rangeSumBST(root->left,  low, high);
        r = rangeSumBST(root->right, low, high);
    } else if (high < val) {
        l = rangeSumBST(root->left,  low, high);
        val = 0;
    }

    return l + r + val;
}
