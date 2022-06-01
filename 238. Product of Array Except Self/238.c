int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int i, product, zero_count;
    int *ret = (int*) malloc(sizeof(int) * numsSize);
    
    for (i=0, zero_count=0, product=1; i<numsSize; ++i) {
        if (nums[i] == 0) {
            zero_count++;
        } else {
            product *= nums[i];
        }
    }
    
    for (i=0; i<numsSize; ++i) {
        if (nums[i] == 0) {
            // There is at least one more zero in nums[]
            if (zero_count > 1) {
                ret[i] = 0;
            } else {
                ret[i] = product;
            }
        } else {
            // There is at least one zero in nums[]
            if (zero_count != 0) {
                ret[i] = 0;
            } else {
                ret[i] = product / nums[i];
            }
        }
    }
    
    *returnSize = numsSize;
    return ret;
}
