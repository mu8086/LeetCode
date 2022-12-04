// https://leetcode.com/problems/minimum-average-difference/

int minimumAverageDifference(int *nums, int numsSize) {
    int i, ansIdx;
    long ansDiff, sum;
    long *longNums = (long *) malloc(sizeof(long) * numsSize);

    for (i = 1, longNums[0] = nums[0]; i < numsSize; ++i) {
        longNums[i] = longNums[i-1] + nums[i];
    }
    sum = longNums[numsSize-1];

    ansIdx = numsSize-1;
    ansDiff = sum / numsSize;

    for (i = numsSize-1; i >= 1; --i) {
        int rSize = numsSize - i;
        long diff  = (longNums[i-1] / i) - (sum - longNums[i-1]) / rSize;
        diff = (diff >= 0) ? diff : -diff;

        if (ansDiff >= diff) {
            ansDiff = diff;
            ansIdx = i-1;
        }
    }

    free(longNums);
    return ansIdx;
}
