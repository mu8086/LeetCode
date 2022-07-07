struct Node {
    int val;
    struct Node* next;
};

typedef struct {
    int size;
    struct Node** queue;
    int frontIndex;
    int rearIndex;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* ret = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));
    ret->size = k;
    ret->queue = (struct Node**) malloc(sizeof(struct Node*) * k);
    memset(ret->queue, 0, sizeof(struct Node*) * k);
    ret->frontIndex = 0;
    ret->rearIndex = 0;
    
    return ret;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj == NULL) {
        return true;
    }
    return obj->queue[obj->rearIndex] == NULL;
}

int getNextIndex(MyCircularQueue* obj, int index) {
    return (index+1) % obj->size;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->queue[obj->rearIndex] != NULL && getNextIndex(obj, obj->rearIndex) == obj->frontIndex;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) {
        return false;
    }
    
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->val = value;
    node->next = NULL;
    
    if (obj->queue[obj->rearIndex] != NULL) {
        obj->queue[obj->rearIndex]->next = node;
        obj->rearIndex = getNextIndex(obj, obj->rearIndex);
        obj->queue[obj->rearIndex] = node;
    } else {    // no node in queue
        obj->queue[obj->rearIndex] = node;
    }
    
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }
    
    if (obj->frontIndex == obj->rearIndex) {    // only one node in queue
        obj->rearIndex = getNextIndex(obj, obj->rearIndex);
    }
    
    free(obj->queue[obj->frontIndex]);
    obj->queue[obj->frontIndex] = NULL;
    obj->frontIndex = getNextIndex(obj, obj->frontIndex);
    
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    return !myCircularQueueIsEmpty(obj) ? obj->queue[obj->frontIndex]->val : -1;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    return !myCircularQueueIsEmpty(obj) ? obj->queue[obj->rearIndex]->val : -1;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    free(obj);
}
