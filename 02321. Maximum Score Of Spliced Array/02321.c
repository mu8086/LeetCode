int getMax(int a, int b) {
    return (a > b) ? a : b;
}

int getSum(int *num, int size) {
    int sum = 0;
    
    while (--size >= 0) {
        sum += num[size];
    }
    
    return sum;
}

int getMaxSubArrSum(int *arr, int size) {
    int i, sum, max = INT_MIN;
    
    for (i = sum = 0; i < size; ++i) {
        sum = getMax(arr[i], sum + arr[i]);
        max = (max > sum) ? max : sum;
    }
    
    return max;
}

int maximumsSplicedArray(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i, maxSubArrSum1, maxSubArrSum2;
    
    int sum1 = getSum(nums1, nums1Size);
    int sum2 = getSum(nums2, nums2Size);
    
    int *allocate = (int *) malloc(sizeof(int) * nums1Size * 2);
    
    int *to1 = allocate;
    int *to2 = allocate + nums1Size;
    
    for (i = 0; i < nums1Size; ++i) {
        to1[i] = nums2[i] - nums1[i];
        to2[i] = -to1[i];
    }
    
    maxSubArrSum1 = getMaxSubArrSum(to1, nums1Size);
    maxSubArrSum2 = getMaxSubArrSum(to2, nums2Size);
    
    free(allocate);
    return getMax(sum1 + maxSubArrSum1, sum2 + maxSubArrSum2);
}
