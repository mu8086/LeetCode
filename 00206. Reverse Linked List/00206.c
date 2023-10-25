// https://leetcode.com/problems/reverse-linked-list

struct ListNode* reverseList(struct ListNode *head) {
    struct ListNode *prev = NULL, *next = NULL;

    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}
