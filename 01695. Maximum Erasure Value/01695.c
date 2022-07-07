#define MAX_VALUE   10000

int maximumUniqueSubarray(int* nums, int numsSize) {
    int i, j, sum, max;
    static int found[MAX_VALUE+1];
    memset(found, -1, sizeof(found));
    
    for (i = 0, j = 1, max = nums[0], found[nums[0]] = 0; j < numsSize; ++j) {
        if (found[nums[j]] >= i) {
            sum = (i > 0)       ? nums[j-1] - nums[i-1] : nums[j-1];
            max = (sum > max)   ? sum                   : max;
            
            i = found[nums[j]] + 1;
        }
        
        found[nums[j]] = j;
        nums[j] += nums[j-1];
    }

    sum = (i > 0)       ? nums[j-1] - nums[i-1] : nums[j-1];
    max = (sum > max)   ? sum                   : max;

    return max;
}
