// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

struct ListNode * deleteMiddle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head, *prev = NULL;

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    free(slow);

    return head;
}
