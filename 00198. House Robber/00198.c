#define MAX_SIZE    100
#define INIT_VAL    -1

int helper(int *nums, int numsSize, int index, int dp[]) {
    if (dp[index] == INIT_VAL) {
        int max;

        if (numsSize == 1) {
            max = nums[index];
        } else if (numsSize == 2) {
            max = (nums[index] > nums[index+1])             ? nums[index]   : nums[index+1];
        } else if (numsSize == 3) {
            max = (max >= nums[index+1])                    ? max           : nums[index+1];
            max = (max >= nums[index] + nums[index+2])      ? max           : nums[index] + nums[index+2];
        } else if (numsSize == 4) {
            max = (max >= nums[index] + nums[index+2])      ? max           : nums[index] + nums[index+2];
            max = (max >= nums[index] + nums[index+3])      ? max           : nums[index] + nums[index+3];
            max = (max >= nums[index+1] + nums[index+3])    ? max           : nums[index+1] + nums[index+3];
        } else {
            int a = nums[index] + helper(nums, numsSize-2, index+2, dp);
            int b = nums[index+1] + helper(nums, numsSize-3, index+3, dp);
            max = (a > b) ? a : b;
        }
        dp[index] = max;
    }
    
    return dp[index];
}

int rob(int *nums, int numsSize) {
    static int dp[MAX_SIZE], size = sizeof(int) * MAX_SIZE;
    memset(dp, INIT_VAL, size);
    
    return helper(nums, numsSize, 0, dp);
}
