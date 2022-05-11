struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int stack_index = 0;
    struct ListNode* walker;
    struct ListNode* stack[31] = {};
    
    for (walker=head; walker!=NULL; walker=walker->next) {
        stack[stack_index++] = walker;
    }
    if (n < stack_index) {
        stack[stack_index-n-1]->next = stack[stack_index-n]->next;
        free(stack[stack_index-n]);
    } else if (n == stack_index) {
        free(stack[0]);
        return stack[1];
    }
    
    return head;
}
