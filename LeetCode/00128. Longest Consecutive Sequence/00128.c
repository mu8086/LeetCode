int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int longestConsecutive(int* nums, int numsSize) {
    int maxLength = 0, length, i;
    
    if (numsSize != 0) {
        qsort(nums, numsSize, sizeof(int), compare);
        
        for (i = 1, length = 1; i < numsSize; ++i) {
            if (nums[i-1] + 1 == nums[i]) {
                ++length;
            } else if (nums[i-1] == nums[i]) {
                continue;
            } else {
                maxLength = (length > maxLength) ? length : maxLength;
                length = 1;
            }
        }
        
        maxLength = (length > maxLength) ? length : maxLength;
    }
    
    return maxLength;
}
