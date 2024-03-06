#define MAX_SIZE    100000

int maxResult(int *nums, int numsSize, int k) {
    int dq[MAX_SIZE] = {};
    int size = 0, front = 0, rear = -1;
    
    for (int i = numsSize-1, max; i > 0; --i) {
        while (size > 0 && dq[front] > i+k-1) {
            ++front;
            --size;
        }

        while (size > 0 && nums[dq[rear]] <= nums[i]) {
            --rear;
            --size;
        }

        dq[++rear] = i;
        ++size;

        nums[i-1] += nums[dq[front]];
    }

    return nums[0];
}
