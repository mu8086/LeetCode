#define MAX_INDEX 1001

struct Node {
    int val;
    struct Node* next;
};

typedef struct {
    struct Node* head;
    struct Node* tail;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* ret = (MyLinkedList*) malloc(sizeof(MyLinkedList));
    ret->head = NULL;
    ret->tail = NULL;
    
    return ret;
}

struct Node* myLinkedListGetNode(MyLinkedList* obj, int index) {
    int i;
    struct Node* walker;
    
    for (i=0, walker=obj->head; i<index && walker != NULL; i++) {
        walker = walker->next;
    }
    
    return walker;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    struct Node* node = myLinkedListGetNode(obj, index);
    return (node != NULL) ? node->val : -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->val = val;
    node->next = obj->head;
    
    obj->head = node;
    obj->tail = (obj->tail == NULL) ? node : obj->tail;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;
    
    if (obj->tail != NULL) {
        obj->tail->next = node;
        obj->tail = node;
    } else {
        obj->head = node;
        obj->tail = node;
    }
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    
    if (index != 0) {
        struct Node* prev = myLinkedListGetNode(obj, index-1);
        if (prev == NULL) {
            return;
        }
        struct Node* node = (struct Node*) malloc(sizeof(struct Node));
        node->val = val;
        node->next = prev->next;
        prev->next = node;
        if (prev == obj->tail) {
            obj->tail = node;
        }
    } else {
        myLinkedListAddAtHead(obj, val);
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    struct Node* tmp;
    
    if (index != 0) {
        struct Node* prev = myLinkedListGetNode(obj, index-1);
        if (prev == NULL) {
            return;
        }
        tmp = prev->next;
        if (tmp == obj->tail) {
            obj->tail = prev;
        }
        prev->next = (tmp != NULL) ? tmp->next : NULL;
    } else {
        tmp = obj->head;
        if (obj->head == obj->tail) {
            obj->head = NULL;
            obj->tail = NULL;
        } else {
            obj->head = obj->head->next;
        }
    }
    
    free(tmp);
}

void myLinkedListFree(MyLinkedList* obj) {
    struct Node* tmp;
    
    while (obj->head != NULL) {
        tmp = obj->head;
        obj->head = obj->head->next;
        free(tmp);
    }
    
    free(obj);
}
