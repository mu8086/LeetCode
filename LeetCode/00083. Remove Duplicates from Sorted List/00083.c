// https://leetcode.com/problems/remove-duplicates-from-sorted-list

struct ListNode * deleteDuplicates(struct ListNode *head) {
    if (head != NULL) {
        struct ListNode *walker = head->next, *prev = head;

        while (walker != NULL) {
            if (prev->val != walker->val) {
                prev = walker;
                walker = walker->next;
            } else {
                prev->next = walker->next;
                free(walker);
                walker = prev->next;
            }
        }
    }

    return head;
}
