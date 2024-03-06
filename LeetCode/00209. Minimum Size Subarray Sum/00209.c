#define INIT_VAL 100001

int minSubArrayLen(int target, int* nums, int numsSize){
    int ret = INIT_VAL;
    int front, end, count;

    for (front=0, end=0, count=0; end<numsSize; end++) {
        count += nums[end];
        
        while (count >= target) {
            ret = (ret < end-front+1) ? ret : end-front+1;
            count -= nums[front++];
        }
    }
    
    return (ret != INIT_VAL) ? ret : 0;
}
