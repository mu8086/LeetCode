struct ListNode * reverseBetween(struct ListNode *head, int left, int right) {
    if (left != right) {
        int i;
        struct ListNode *revL = NULL, *revR = NULL;
        struct ListNode *tmp = NULL, *prev_left = NULL;
        
        for (i = 1, revR = head; i < left; ++i) {
            prev_left = revR;
            revR = revR->next;
        }
        revL = revR;
        
        for ( ; i < right; ++i) {
            if (revR->next != NULL) {
                tmp = revR->next->next;
                revR->next->next = revL;
            }
            revL = revR->next;
            revR->next = tmp;
        }
        
        if (prev_left == NULL) {
            head = revL;
        } else {
            prev_left->next = revL;
        }
    }

    return head;
}
