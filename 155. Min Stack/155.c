struct Node {
    int val;
    struct Node* next;
};

typedef struct {
    int size;
    struct Node* top;
} MinStack;


MinStack* minStackCreate() {
    MinStack* ret = (MinStack*) malloc(sizeof(MinStack));
    ret->size = 0;
    ret->top = NULL;
    
    return ret;
}

void minStackPush(MinStack* obj, int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = obj->top;
    
    obj->top = newNode;
    (obj->size)++;
}

void minStackPop(MinStack* obj) {
    if (obj != NULL) {
        struct Node* tmp = obj->top;

        obj->top = obj->top->next;
        (obj->size)--;

        free(tmp);
    }
}

int minStackTop(MinStack* obj) {
    return obj->top->val;
}

int minStackGetMin(MinStack* obj) {
    int min = obj->top->val;

    for (struct Node* walker = obj->top; walker != NULL; walker = walker->next) {
        min = (min < walker->val) ? min : walker->val;
    }
    
    return min;
}

void minStackFree(MinStack* obj) {
    if (obj != NULL) {
        struct Node* walker, *last;

        for (walker = obj->top, last = NULL; walker != NULL; walker = walker->next) {
            if (last != NULL) {
                free(last);
            }
            last = walker;
        }
        if (last != NULL) {
            free(last);
        }
        
        free(obj);
    }
}
