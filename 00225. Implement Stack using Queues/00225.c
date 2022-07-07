typedef struct {
    int index;
    int nums[100];
} MyStack;

MyStack* myStackCreate() {
    MyStack* myStack = (MyStack*) malloc(sizeof(MyStack));
    myStack->index = -1;
    return myStack;
}

void myStackPush(MyStack* obj, int x) {
    obj->nums[++(obj->index)] = x;
}

int myStackPop(MyStack* obj) {
    return obj->nums[obj->index--];
}

int myStackTop(MyStack* obj) {
    return obj->nums[obj->index];
}

bool myStackEmpty(MyStack* obj) {
    return obj->index == -1 ? true : false;
}

void myStackFree(MyStack* obj) {
    free(obj);
}
