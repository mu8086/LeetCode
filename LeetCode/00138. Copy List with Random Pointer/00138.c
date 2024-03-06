void doubleTheList(struct Node* head) {
    struct Node* newNode = NULL;
    
    while (head != NULL) {
        newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->val = head->val;
        newNode->next = head->next;
        newNode->random = NULL;
        head->next = newNode;
        head = newNode->next;
    }
}

void copyRandom(struct Node* head) {
    while (head != NULL) {
        if (head->random != NULL) {
            head->next->random = head->random->next;
        }
        head = head->next->next;
    }
}

void splitTo2List(struct Node* ori, struct Node* ret) {
    while (ori != NULL) {
        ori->next = ret->next;
        ret->next = (ori->next != NULL) ? ret->next->next : NULL;
        ori = ori->next;
        ret = ret->next;
    }
}

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    
    struct Node* ret = NULL;
    
	doubleTheList(head);
    copyRandom(head);
    
    ret = head->next;
    splitTo2List(head, ret);
    
    return ret;
}
