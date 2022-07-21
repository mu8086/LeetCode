#define MAX_SIZE    10000
#define EMPTY       -1

bool isStackEmpty(int size) {
    return size == EMPTY;
}

bool isSameSign(int a, int b) {
    return ((a > 0 && b > 0) || (a < 0 && b < 0));
}

int getLeft(int a, int b) {
    if (a + b != 0) {
        return isSameSign(a, a+b) ? a : b;
    }
    return 0;
}

int pop(int stack[], int *size) {
    return stack[(*size)--];
}

void push(int stack[], int *size, int val) {
    if (isStackEmpty(*size)) {
        stack[++(*size)] = val;
    } else {
        int left, top = stack[*size];
        
        if (isSameSign(top, val) || top < 0) {
            stack[++(*size)] = val;
        } else {
            top = pop(stack, size);
            left = getLeft(top, val);
            if (left != 0) {
                push(stack, size, left);
            }
        }
    }
}

int * asteroidCollision(int *asteroids, int asteroidsSize, int *returnSize) {
    int i, *ans = NULL;
    int stackSize = EMPTY, stack[MAX_SIZE] = {};
    
    for (i = 0; i < asteroidsSize; ++i) {
        push(stack, &stackSize, asteroids[i]);
    }
    
    if (!isStackEmpty(stackSize)) {
        ans = (int *) malloc(sizeof(int) * (stackSize+1));
        for (i = 0; i <= stackSize; ++i) {
            ans[i] = stack[i];
        }
    }
    
    *returnSize = stackSize+1;
    return ans;
}
