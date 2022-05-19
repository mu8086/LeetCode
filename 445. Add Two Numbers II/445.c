int listReverse(struct ListNode** head) {
    int node_count = 0;
    struct ListNode* tmp, *walker = *head;
    
    if (*head != NULL) {
        node_count++;
    }
    while (walker->next != NULL) {
        tmp = walker->next;
        walker->next = tmp->next;
        tmp->next = *head;
        *head = tmp;
        node_count++;
    }
    
    return node_count;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry, newVal, tmp, l1_count, l2_count;
    struct ListNode* tmp_list = NULL, *w1, *w2, *last;
    
    l1_count = listReverse(&l1);
    l2_count = listReverse(&l2);
    
    if (l1_count < l2_count) {  // let 'l1' to be the longer list
        tmp_list = l1, l1 = l2, l2 = tmp_list;
        tmp = l1_count, l1_count = l2_count, l2_count = tmp;
    }
    
    carry = 0;
    w1 = l1, w2 = l2;
    while (w1 != NULL) {
        newVal = w1->val + carry;
        if (w2 != NULL) {
            newVal += w2->val;
            w2 = w2->next;
        } else if (carry == 0) {
            break;
        }
        
        w1->val = newVal % 10;
        carry = newVal / 10;
        
        last = w1;
        w1 = w1->next;
    }
    if (carry != 0) {
        last->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        last->next->val = 1;
        last->next->next = NULL;
    }
    
    listReverse(&l1);
    
    return l1;
}
