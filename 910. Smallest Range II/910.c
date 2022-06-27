int getMax(int a, int b) {
    return (a > b) ? a : b;
}

int getMin(int a, int b) {
    return (a < b) ? a : b;
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int smallestRangeII(int* nums, int numsSize, int k) {
    int i, lastI, a, b, high, low;
    
    qsort(nums, numsSize, sizeof(int), compare);
    
    int tmpa = nums[numsSize-1] - k;
    int tmpb = nums[0] + k;
    
    int ans = nums[numsSize-1] - nums[0];
    for (i = 0, lastI = numsSize-2; i <= lastI; ++i) {
        a = nums[i] + k, b = nums[i+1] - k;
        
        high = getMax(tmpa, a);
        low = getMin(tmpb, b);
        
        ans = getMin(ans, high - low);
    }
    
    return ans;
}
