struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* result = l2;
    
    while (l1->next != NULL && l2->next != NULL) {
        l2->val += l1->val;
        if (l2->val > 9) {
            l2->val -= 10;
            l2->next->val += 1;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l2->next == NULL) {
        l2->next = l1->next;
    }
    
    l2->val += l1->val;
    while (l2->val > 9) {
        l2->val -= 10;
        if (l2->next == NULL) {
            l2->next = malloc(sizeof (struct ListNode));
            l2->next->val = 1;
            l2->next->next = NULL;
            return result;
        }
        l2->next->val += 1;
        l2 = l2->next;
    }
    
    return result;
}
