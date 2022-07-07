#define NOT_FOUND -1

int circularFindGreater(int* nums, int numsSize, int index) {
    for (int i=index+1, rewind=0; i!=index && rewind<=1; i++) {
        if (i >= numsSize) {
            i %= numsSize;
            rewind++;
            if (rewind > 1) {
                break;
            }
        }
        
        if (nums[i] > nums[index]) {
            return i; 
        }
    }
    
    return NOT_FOUND;
}

int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    
    if (*returnSize == 1) {
        nums[0] = -1;
        return nums;
    }

    int i, tmp;
    int ret_size = sizeof(int) * *returnSize;
    int* ret = (int*) malloc(ret_size);
    memset(ret, 0, ret_size);
    
    for (i=0; i<numsSize; i++) {
        tmp = circularFindGreater(nums, numsSize, i);
        ret[i] = (tmp != NOT_FOUND) ? nums[tmp] : NOT_FOUND;
    }

    return ret;
}
