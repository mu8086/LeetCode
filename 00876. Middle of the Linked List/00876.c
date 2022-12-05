// https://leetcode.com/problems/middle-of-the-linked-list

struct ListNode * middleNode(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
        }

        slow = slow->next;
    }

    return slow;
}
