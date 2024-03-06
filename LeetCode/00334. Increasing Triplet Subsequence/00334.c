// https://leetcode.com/problems/increasing-triplet-subsequence/

bool increasingTriplet(int * nums, int numsSize) {
    for (int idx = 0, i = INT_MAX, j = INT_MAX; idx < numsSize; ++idx) {
        if (nums[idx] <= i) {
            i = nums[idx];
        } else if (nums[idx] <= j) {
            j = nums[idx];
        } else {
            return true;
        }
    }

    return false;
}
