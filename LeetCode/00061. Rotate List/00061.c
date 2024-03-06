int getListLength(struct ListNode* list) {
    int node_count = 0;
    
    for (; list != NULL; list = list->next) {
        node_count++;
    }
    
    return node_count;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL) {
        return NULL;
    }
    
    k %= getListLength(head);
    
    if (k != 0) {
        struct ListNode* tmp, *fast, *slow;
        
        for (fast = slow = head; k>0; k--) {
            fast = fast->next;
        }
        
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        fast->next = head;
        head = slow->next;
        slow->next = NULL;        
    }
    
    return head;
}
