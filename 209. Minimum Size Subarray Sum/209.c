#define INIT_VAL 100001

int minSubArrayLen(int target, int* nums, int numsSize){
    int ret = INIT_VAL;
    int front, end, count;

    for (front=0, end=0, count=0; ; ) {
        if (count < target) {
            if (end >= numsSize) {
                break;
            }
            count += nums[end++];
        } else if (count >= target) {
            ret = (ret < end-front) ? ret : end-front;
            count -= nums[front++];
        }
    }
    
    return (ret != INIT_VAL) ? ret : 0;
}
