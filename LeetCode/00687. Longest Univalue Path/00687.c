int maxDepthOfUnivalue(struct TreeNode *root, int val, int *ans) {
    int res = 0;

    if (root != NULL) {
        int l, r;
        bool newChain = false;

        if (val != root->val) {
            val = root->val;
            newChain = true;
        }

        l = maxDepthOfUnivalue(root->left,  val, ans);
        r = maxDepthOfUnivalue(root->right, val, ans);

        res = (newChain) ? 0 : (l > r) ? l+1 : r+1;

        // use current root as a valid path, connect its left and right
        if (*ans < l+r+1) {
            *ans = l+r+1;
        }
    }

    return res;
}

int longestUnivaluePath(struct TreeNode *root) {
    int ans = 0;

    if (root != NULL) {
        maxDepthOfUnivalue(root, root->val, &ans);
    }

    return (ans > 0) ? ans-1 : ans;
}
