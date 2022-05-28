int missingNumber(int *nums, int numsSize) {
    int sum = (1 + numsSize) * numsSize / 2;
    
    while (numsSize > 0) {
        sum -= nums[--numsSize];
    }
    
    return sum;
}
