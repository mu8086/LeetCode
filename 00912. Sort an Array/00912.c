void merge(int *nums, int begin, int mid, int end) {
    int i, j, k, combineSize = sizeof(int) * (end - begin + 1);
    int *combine = (int *) malloc(combineSize);

    for (i = begin, j = mid+1, k = 0; i <= mid && j <= end; ) {
        if (nums[i] <= nums[j]) {
            combine[k++] = nums[i++];
        } else {
            combine[k++] = nums[j++];
        }
    }
    
    while (i <= mid) {
        combine[k++] = nums[i++];
    }
    
    while (j <= end) {
        combine[k++] = nums[j++];
    }
    
    memcpy(nums + begin, combine, combineSize);
    free(combine);
}

void mergeSort(int *nums, int begin, int end) {
    if (begin < end) {
        int mid = begin + (end - begin) / 2;
        
        mergeSort(nums, begin, mid);
        mergeSort(nums, mid+1, end);
        
        merge(nums, begin, mid, end);
    }
}

int * sortArray(int *nums, int numsSize, int *returnSize) {
    mergeSort(nums, 0, numsSize-1);
    *returnSize = numsSize;
    return nums;
}
