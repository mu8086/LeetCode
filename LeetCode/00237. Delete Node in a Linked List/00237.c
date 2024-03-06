// https://leetcode.com/problems/delete-node-in-a-linked-list/

void deleteNode(struct ListNode *node) {
    *node = *(node->next);
}
