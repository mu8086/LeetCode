// https://leetcode.com/problems/linked-list-cycle

bool hasCycle(struct ListNode *head) {
    if (head == NULL) {
        return false;
    }

    for (int i = 0; i < 10000; i++) {
        if (head->next == NULL) {
            return false;
        }
        head = head->next;
    }

    return true;
}
