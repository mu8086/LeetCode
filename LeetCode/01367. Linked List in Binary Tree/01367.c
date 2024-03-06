bool matchList(struct ListNode* head, struct TreeNode* root) {
    if (head == NULL) {         // match all list node
        return true;
    } else if (root == NULL) {  // not match all list node
        return false;
    }
    return (head->val == root->val) && (matchList(head->next, root->right) || matchList(head->next, root->left));
}

bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    if (head == NULL) {
        return true;
    } else if (root == NULL) {
        return false;
    }
    return matchList(head, root) || isSubPath(head, root->right) || isSubPath(head, root->left);
}
