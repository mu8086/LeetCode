int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int minMoves2(int* nums, int numsSize) {
    int i, sum, target;
    
    qsort(nums, numsSize, sizeof(int), compare);

    target = nums[numsSize/2];
    for (i = 0, sum = 0; i < numsSize; ++i) {
        sum += abs(target - nums[i]);
    }
    
    return sum;
}
