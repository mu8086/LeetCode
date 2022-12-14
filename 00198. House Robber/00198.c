// https://leetcode.com/problems/house-robber/

int rob(int *nums, int size) {
    if (size == 1) {
        return nums[0];
    } else if (size > 2) {
        nums[2] += nums[0];
        for (int i = 3; i < size; ++i) {
            nums[i] += fmax(nums[i-3], nums[i-2]);
        }
    }

    return fmax(nums[size-2], nums[size-1]);
}
