struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    struct ListNode *second = head->next;
    
    head->next = swapPairs(second->next);
    second->next = head;
        
    return second;
}
