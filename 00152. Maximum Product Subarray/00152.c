// https://leetcode.com/problems/maximum-product-subarray/

int maxProduct(int * nums, int numsSize) {
    int i, ans, a, b, max, min;

    for (i = 1, ans = max = min = nums[0]; i < numsSize; ++i) {
        if (nums[i] != 0) {
            a = max * nums[i];
            b = min * nums[i];

            max = fmax(nums[i], fmax(a, b));
            min = fmin(nums[i], fmin(a, b));
        } else {
            max = min = 0;
        }

        if (ans < max) {
            ans = max;
        }
    }

    return ans;
}
