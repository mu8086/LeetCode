struct ListNode* mergeNodes(struct ListNode* head){
    struct ListNode* node, *res_index;
    struct ListNode* pre_head = malloc(sizeof(struct ListNode));
    pre_head->next = head;
    int sum;
    
    for (sum=0, res_index=pre_head, node=head->next; node!=NULL; node=node->next) {
        if (node->val != 0) {
            sum+=node->val;
        } else {
            if (sum != 0) {
                res_index=res_index->next;
                res_index->val=sum;
            }
            sum=0;
        }
    }
    res_index->next=NULL;
    
    return head;
}
