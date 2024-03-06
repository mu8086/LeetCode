// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

struct ListNode * removeNthFromEnd(struct ListNode * head, int n) {
    struct ListNode *fast = head, *slow = NULL, *last = NULL;

    for (int i = 0; i < n; ++i) {
        fast = fast->next;
    }

    for (slow = head, last = NULL; fast != NULL; fast = fast->next, slow = slow->next) {
        last = slow;
    }

    if (slow == head) {
        head = head->next;
    } else {
        last->next = slow->next;
    }

    free(slow);
    return head;
}
