/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isBalanced(struct TreeNode* root){
    if (root == NULL) {
        return true;
    }
    if (root->left == NULL && root->right == NULL) {
        root->val = 1;
        return true;
    } else if (root->left == NULL) {
        if (!isBalanced(root->right))
            return false;
        if (root->right->val != 1) {
            return false;
        } else {
            root->val = 2;
            return true;
        }
    } else if (root->right == NULL) {
        if (!isBalanced(root->left))
            return false;
        if (root->left->val != 1) {
            return false;
        } else {
            root->val = 2;
            return true;
        }
    } else {
        if (isBalanced(root->left) && isBalanced(root->right)) {
            int diff = root->left->val - root->right->val;
            if (diff < -1 || 1 < diff)
                return false;
            
            int bigger = (root->left->val > root->right->val) \
                ? root->left->val : root->right->val;
            root->val = bigger+1;
            return true;
        } else {
            return false;
        }
    }
}
