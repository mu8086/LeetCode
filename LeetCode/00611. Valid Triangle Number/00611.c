int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int find_max_index_less_than_tmp(int target, int *nums, int start_index, int end_index) {
    if (start_index > end_index) {
        return 0;
    } else if (start_index == end_index) {
        return nums[start_index] < target ? start_index : 0;
    }
    
    int half_index = (start_index + end_index) / 2, tmp;
    
    if (nums[half_index] >= target) {
        return find_max_index_less_than_tmp(target, nums, start_index, half_index);
    } else {
        tmp = find_max_index_less_than_tmp(target, nums, half_index+1, end_index);
        return (tmp != 0) ? tmp : half_index;
    }
}

int triangleNumber(int* nums, int numsSize){
    int ret = 0, zero;
    
    qsort(nums, numsSize, sizeof(int), compare);
    for (zero=0; zero<numsSize; zero++) {
        if (nums[zero] != 0) {
            break;
        }
    }
    nums = &nums[zero];
    numsSize -= zero;
    
    if (numsSize > 2) {
        int i, max_i, j, max_j, k, max_k, tmp;
        
        for (i=0, max_i=numsSize-3; i<=max_i; i++) {
            for (j=i+1, max_j=numsSize-2, k=j+1; j<=max_j; j++) {
                tmp = nums[i] + nums[j];
                k = find_max_index_less_than_tmp(tmp, nums, k, numsSize-1);
                ret += (k != 0) ? k-j : 0;
            }
        }
    }
    
    return ret;
}
