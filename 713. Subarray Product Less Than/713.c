int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    int ret = 0;
    
    if (k <= 1) {
        return 0;
    }
    
    int left = 0, right = 0, product = 1;
    for (right = 0; right<numsSize; right++) {
        product *= nums[right];
        while (product >= k) {
            product /= nums[left++];
        }
        ret += (right - left + 1);
    }
    
    return ret;
}
