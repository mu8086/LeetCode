#define INIT_VAL 100001

int minOperations(int* nums, int numsSize, int x){
    int ret = INIT_VAL, operations;
    int count, last_index = numsSize-1;
    int front_end, back_begin;
    
    for (front_end=0, count=0; front_end<numsSize && count<x; front_end++) {
        count += nums[front_end];
    }
    if (count == x) {
        ret = front_end;
    } else if (count<x && front_end == numsSize) { // x > sum of array
        return -1;
    }

    for (front_end--, back_begin=last_index; front_end>=0; front_end--) {
        count -= nums[front_end];
        
        while (count < x && back_begin >= 0) {
            count += nums[back_begin--];
        }
        if (count == x) {
            operations = (front_end) + (last_index-back_begin);
            ret = (operations < ret) ? operations : ret;
        }
    }

    return ret != INIT_VAL ? ret : -1;
}
