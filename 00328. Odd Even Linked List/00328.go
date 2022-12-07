// https://leetcode.com/problems/odd-even-linked-list/description

struct ListNode * oddEvenList(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    int i;
    struct ListNode *walker = NULL, *odd = NULL, *even = NULL;
    struct ListNode *evenHead = head->next;

    for (walker = head, i = 1; walker != NULL; ++i) {
        if (i & 1) {
            odd = walker;
            walker = walker->next;
        } else {
            even = walker;
            walker = walker->next;
            
            odd->next = even->next;
            if (even->next != NULL) {
                even->next = even->next->next;
            }
        }
    }
    odd->next = evenHead;

    return head;
}
