// https://leetcode.com/problems/sum-root-to-leaf-numbers

void helper(struct TreeNode *root, int sum, int *ans) {
    if (root == NULL) {
        return;
    }

    sum = sum * 10 + root->val;
    if (root->left == NULL && root->right == NULL) {
        *ans += sum;
    } else {
        helper(root->left, sum,  ans);
        helper(root->right, sum, ans);
    }
}

int sumNumbers(struct TreeNode *root) {
    int ans = 0;

    helper(root, 0, &ans);

    return ans;
}
