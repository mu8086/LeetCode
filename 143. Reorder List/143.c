void reorderList(struct ListNode* head){
    int index = 0, size = 0, last;
    struct ListNode* walker, *queue[50000];
    
    for (walker=head; walker!=NULL; walker=walker->next) {
        queue[size++] = walker;
    }
    
    // if there is a position between [index] and [index+1] to insert [last n]
    for (last = size-1; index+1 < last; index++, last--) {
        queue[last]->next = queue[index]->next;
        queue[index]->next = queue[last];
    }
    queue[last]->next = NULL;
}
