int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j, diff;
    *returnSize=2;
    int *ret = malloc(sizeof (int) **returnSize);
    
    for (i=0, diff=0; i<numsSize; i++) {
        diff = target-nums[i];
        for (j=i+1; j<numsSize; j++) {
            if (nums[j] == diff) {
                *ret = i;
                *(ret+1) = j;
                return ret;
            }
        }
    }
    return ret;
}
