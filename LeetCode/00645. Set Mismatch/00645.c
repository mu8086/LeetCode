// https://leetcode.com/problems/set-mismatch

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int * findErrorNums(int *nums, int numsSize, int *returnSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    *returnSize = 2;
    int *ans = (int *) malloc(sizeof(int) * 2);
    ans[0] = 0;
    ans[1] = (nums[0] == 1) ? 0 : 1;

    for (int i = 1, tmp = 1; i < numsSize; ++i) {
        if (nums[i-1] == nums[i]) {
            ans[0] = nums[i];
        } else if (nums[i-1]+1 < nums[i]) {
            ans[1] = nums[i-1]+1;
        }
    }

    if (ans[1] == 0) {
        ans[1] = numsSize;
    }
    return ans;
}
