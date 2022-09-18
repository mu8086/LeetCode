int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

bool search(int *nums, int numsSize, int target) {
    int begin = 0, end = numsSize-1, mid, midVal;

    while (begin <= end) {
        mid = (begin + end) >> 1;
        midVal = nums[mid];

        if (midVal == target) {
            return true;
        } else if (midVal < target) {
            begin = mid+1;
        } else {
            end = end-1;
        }
    }

    return false;
}

int findPairs(int *nums, int numsSize, int k) {
    int i, pair = 0;

    qsort(nums, numsSize, sizeof(int), compare);

    for (i = numsSize-1; i > 0; --i) {
        if (i == numsSize-1 || nums[i+1] != nums[i]) {
            if (search(nums, i, nums[i]-k)) {
                ++pair;
            }
        }
    }

    return pair;
}
