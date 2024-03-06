#define MAX_SIZE 100000

int * maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize) {
    if (numsSize == 1 || k == 1) {
        *returnSize = numsSize;
        return nums;
    }
    
    *returnSize = numsSize - k + 1;
    int *ret = (int *) malloc(sizeof(int) * (numsSize - k + 1));
    
    int front = 0, rear = -1, size = 0;
    int dq[MAX_SIZE] = {};
    
    for (int i = 0, j = 1-k; i < numsSize; ++i, ++j) {
        while (size > 0 && dq[front] <= i-k) {
            ++front;
            --size;
        }
        while (size > 0 && nums[dq[rear]] <= nums[i]) {
            --rear;
            --size;
        }
        dq[++rear] = i;
        ++size;
        
        if (j >= 0) {
            ret[j] = nums[dq[front]];
        }
    }

    return ret;
}
