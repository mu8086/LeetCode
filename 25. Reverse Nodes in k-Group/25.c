#define OK      0
#define ERROR   1

int getKthNode(struct ListNode **kthNode, struct ListNode *head, int k) {
    while (head != NULL && --k > 0) {
        head = head->next;
    }
    *kthNode = head;
    
    return (k == 0) ? OK : ERROR;
}

struct ListNode * listReverse(struct ListNode* head) {
    struct ListNode* tmp, *walker = head;
    
    if (walker != NULL) {
        while (walker->next != NULL) {
            tmp = walker->next;
            walker->next = tmp->next;
            tmp->next = head;
            head = tmp;
        }
    }
    
    return head;
}

struct ListNode * reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* kthNode = NULL, *tmp = NULL;
    
    if (k != 1 && getKthNode(&kthNode, head, k) == OK) {
        tmp = reverseKGroup(kthNode->next, k);
        
        kthNode->next = NULL;
        kthNode = head;
        head = listReverse(head);
        
        kthNode->next = tmp;
    }
    
    return head;
}
