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

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int *nums, int size, int rootIndex) {
    int largestIndex = rootIndex;
    int lIndex = rootIndex*2+1, rIndex = rootIndex*2+2;
    
    if (lIndex < size && nums[lIndex] > nums[largestIndex]) {
        largestIndex = lIndex;
    }
    
    if (rIndex < size && nums[rIndex] > nums[largestIndex]) {
        largestIndex = rIndex;
    }
    
    if (largestIndex != rootIndex) {
        swap(&nums[rootIndex], &nums[largestIndex]);
        // after swap, nums[rootIndex]    -> largest number
        //             nums[largestIndex] -> original nums[rootIndex] (un-heapify)
        heapify(nums, size, largestIndex);
    }
}

// MaxHeap
void heapSort(int *nums, int size) {
    for (int i = size/2-1; i >= 0; --i) {
        heapify(nums, size, i);
    }
    
    for (int i = size-1; i >= 0; --i) {
        swap(&nums[0], &nums[i]);
        heapify(nums, i, 0);
    }
}

int * sortArray(int *nums, int numsSize, int *returnSize) {
    //mergeSort(nums, 0, numsSize-1);
    heapSort(nums, numsSize);
    *returnSize = numsSize;
    return nums;
}
