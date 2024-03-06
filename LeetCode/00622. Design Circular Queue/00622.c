#define UNSET   -1


typedef struct {
    int *val;
    int size;
    int front;
    int rear;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *queue = (MyCircularQueue *) malloc(sizeof(MyCircularQueue));
    int *val = (int *) malloc(sizeof(int) * k);
    memset(val, UNSET, sizeof(int) * k);

    *queue = (MyCircularQueue){ .val = val, .size = k, .front = 0, .rear = 0 };

    return queue;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->rear && obj->val[obj->front] == UNSET;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->front == obj->rear && obj->val[obj->front] != UNSET;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) {
        return false;
    }

    obj->val[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->size;

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }

    obj->val[obj->front] = UNSET;
    obj->front = (obj->front + 1) % obj->size;

    return true;
}

int myCircularQueueFront(MyCircularQueue *obj) {
    return myCircularQueueIsEmpty(obj) ? -1 : obj->val[obj->front];
}

int myCircularQueueRear(MyCircularQueue *obj) {
    int idx = (obj->rear + obj->size - 1) % obj->size;
    return myCircularQueueIsEmpty(obj) ? -1 : obj->val[idx];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if (obj != NULL) {
        free(obj->val);
        free(obj);
    }
}
