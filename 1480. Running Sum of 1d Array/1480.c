int* runningSum(int* nums, int numsSize, int* returnSize){
    int i, sum, *ret = (int*) malloc(sizeof(int) * numsSize);
    
    for (i=0, sum=0; i<numsSize; ++i) {
        sum += nums[i];
        ret[i] = sum;
    }

    *returnSize = numsSize;
    return ret;
}
