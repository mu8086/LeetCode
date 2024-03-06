int * sumEvenAfterQueries(int *nums, int numsSize, int **queries, int queriesSize, int *queriesColSize, int *returnSize) {
    int i, evenSum, val, idx;
    int *ret = (int *) malloc(sizeof(int) * queriesSize);

    for (i = 0, evenSum = 0; i < numsSize; ++i) {
        if (!(nums[i] & 1)) {
            evenSum += nums[i];
        }
    }

    for (i = 0; i < queriesSize; ++i) {
        val = queries[i][0];
        idx = queries[i][1];

        if (!(nums[idx] & 1)) {
            evenSum -= nums[idx];
        }

        nums[idx] += val;
        if (!(nums[idx] & 1)) {
            evenSum += nums[idx];
        }

        ret[i] = evenSum;
    }

    *returnSize = queriesSize;
    return ret;
}
