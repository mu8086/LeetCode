struct ListNode * partition(struct ListNode *head, int x) {
    struct ListNode *walker = head, *newWalker = NULL;
    struct ListNode *lessHead = NULL, *lessEnd = NULL;
    struct ListNode *greaterHead = NULL, *greaterEnd = NULL;
    
    while (walker != NULL) {
        newWalker = walker->next;
        walker->next = NULL;
        
        if (walker->val < x) {
            if (lessHead == NULL) {
                lessHead = walker;
                lessEnd  = walker;
            } else {
                lessEnd->next = walker;
                lessEnd = walker;
            }
        } else {
            if (greaterHead == NULL) {
                greaterHead = walker;
                greaterEnd  = walker;
            } else {
                greaterEnd->next = walker;
                greaterEnd = walker;
            }
        }
        
        walker = newWalker;
    }
    if (lessEnd != NULL) {
        lessEnd->next = greaterHead;
    }
    
    return (lessHead != NULL) ? lessHead : greaterHead;
}
