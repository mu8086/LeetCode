// https://leetcode.com/problems/count-complete-tree-nodes

int countNodes(struct TreeNode* root){
    if (root != NULL) {
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    return 0;
}
