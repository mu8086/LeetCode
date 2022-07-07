int compare(const void* a, const void* b) {
    return *((const int*) a) > *((const int*) b);
}

void sort(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void nextPermutation(int* nums, int numsSize){  
    for (int i, j=numsSize-2; j>=0; j--) {
        for (i=numsSize-1; i>j; i--) {
            if (nums[i] > nums[j]) {
                swap(&nums[i], &nums[j]);
                sort(&nums[j+1], numsSize-j-1);
                return;
            }
        }
    }

    sort(nums, numsSize);
    return;
}
