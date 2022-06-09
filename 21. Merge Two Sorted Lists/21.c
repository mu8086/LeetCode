struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    
    struct ListNode* ret = NULL, *tmp = NULL;
    
    if (list1->val <= list2->val) {
        ret = tmp = list1;
        list1 = list1->next;
    } else {
        ret = tmp = list2;
        list2 = list2->next;
    }
    
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tmp->next = list1;
            list1 = list1->next;
        } else {
            tmp->next = list2;
            list2 = list2->next;
        }
        tmp = tmp->next;
    }
    
    tmp->next = (list1 != NULL) ? list1 : list2;
    
    return ret;
}
