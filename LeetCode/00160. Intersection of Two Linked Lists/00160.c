struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int sizeA, sizeB;
    struct ListNode *tmp, *A, *B;
    
    for (sizeA = 0, A = headA; A != NULL; ++sizeA) {
        A = A->next;
    }
    
    for (sizeB = 0, B = headB; B != NULL; ++sizeB) {
        B = B->next;
    }

    if (sizeA < sizeB) {
        sizeA   = sizeB - sizeA;
        
        tmp     = headA;
        headA   = headB;
        headB   = tmp;
    } else {
        sizeA   = sizeA - sizeB;
    }
    
    while (--sizeA >= 0) {
        headA = headA->next;
    }
    
    while (headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }
    
    return headA;
}
