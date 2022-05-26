#define MODULO_VAL 1000000007

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int productNums(int *nums, int numsSize) {
    long long ret = nums[0];
    
    for (int i=1; i<numsSize; i++) {
        ret *= (long long) nums[i];
        ret %= MODULO_VAL;
    }
    
    return (int)ret;
}

int maximumProduct(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int last_index = numsSize-1, lowest_value_index;
    
    for (lowest_value_index=0; k > 0; ) {
        if (lowest_value_index == last_index || nums[lowest_value_index] < nums[lowest_value_index+1]) {
            k--;
            nums[lowest_value_index]++;
            if (lowest_value_index > 0) {
                lowest_value_index--;
            }
        } else {
            lowest_value_index++;
        }
    }
    
    return (nums[0] != 0) ? productNums(nums, numsSize) : 0;
}
