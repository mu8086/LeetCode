#define INVALID -1

int getSum(int *num, int size) {
    int sum = 0;
    
    while (--size >= 0) {
        sum += num[size];
    }
    
    return sum;
}

int * getDiff(int *n1, int *n2, int size) {
    int i, *diff = (int *) malloc(sizeof(int) * size);
    
    for (i = 0; i < size; ++i) {
        diff[i] = n1[i] - n2[i];
    }
    
    return diff;
}

int get1Continous(int *diff, int size, int *index, int *endI) {
    int l, r, sum, max;
    
    *index = INVALID;
    *endI  = INVALID;
    
    for (l = r = sum = max = 0; r < size; ) {
        sum += diff[r++];
        while (sum < 0) {
            sum -= diff[l++];
        }

        if (sum > max) {
            max = sum;
            *index = l;
            *endI  = r-1;
        }
    }
    
    return max;
}

int get2Continous(int *diff, int size, int *index, int *endI) {
    int i, max;
    
    for (i = 0; i < size; ++i) {
        diff[i] = -diff[i];
    }
    
    max = get1Continous(diff, size, index, endI);
    
    for (i = 0; i < size; ++i) {
        diff[i] = -diff[i];
    }
    
    return -max;
}

int swapArr(int *n1, int *n2, int i, int e) {
    int sum, tmp;

    for (sum = 0; i <= e; ++i) {
        sum += n1[i] - n2[i];
        tmp = n1[i];
        n1[i] = n2[i];
        n2[i] = tmp;
    }
    
    return sum;
}

int maximumsSplicedArray(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i1, i2, sum1, sum2, e1, e2, i, tmp, max, ret, dif;
    int *diff = getDiff(nums1, nums2, nums1Size);
    
    sum1 = get1Continous(diff, nums1Size, &i1, &e1);
    sum2 = -get2Continous(diff, nums1Size, &i2, &e2);
    
    if (i1 == INVALID) {
        return getSum(nums2, nums2Size);
    } else if (i2 == INVALID) {
        return getSum(nums1, nums1Size);
    }
    
    sum1 = getSum(nums1, nums1Size);
    sum2 = getSum(nums2, nums2Size);
    max = (sum1 > sum2) ? sum1 : sum2;
    ret = max;
    
    dif = swapArr(nums1, nums2, i1, e1);
    sum1 -= dif;
    sum2 += dif;
    max = (sum1 > sum2) ? sum1 : sum2;
    ret = (max > ret) ? max : ret;
    
    dif = swapArr(nums1, nums2, i1, e1);
    sum1 -= dif;
    sum2 += dif;
    
    dif = swapArr(nums1, nums2, i2, e2);
    sum1 -= dif;
    sum2 += dif;
    max = (sum1 > sum2) ? sum1 : sum2;
    ret = (max > ret) ? max : ret;
    
    return ret;
}
