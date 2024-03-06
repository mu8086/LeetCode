int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    
    int *res = (int *)malloc(sizeof(int)*numsSize);
    int even_index=0, odd_index=numsSize-1;
    
    for (int i=0, num; i<numsSize; i++) {
        num = nums[i];
        if (num & 1) {  // odd
            res[odd_index] = num;
            odd_index--;
        } else { // even
            res[even_index] = num;
            even_index++;
        }
    }
    
    return res;
}
