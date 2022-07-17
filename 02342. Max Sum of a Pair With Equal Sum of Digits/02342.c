int sumDigits(int num) {
    int sum = 0;
    
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    
    return sum;
}

int ** int2dArray(int m, int n) {
    int **ret = (int **) malloc(sizeof(int *) * m + sizeof(int) * m * n);
    int *first = (int *)(ret + m);
    
    for (int i = 0; i < m; ++i) {
        ret[i] = first + i * n;
    }
    
    return ret;
}

int compare(const void *aa, const void *bb) {
    int *a = *(int **)aa, *b = *(int **)bb;
    
    if (a[1] == b[1]) {
        return b[0] - a[0];
    }
    return b[1] - a[1];
}

int maximumSum(int *nums, int numsSize) {
    int max = -1, i, num, sum, lastIndex;
    int **tmp = int2dArray(numsSize, 2);
    
    for (i = 0; i < numsSize; ++i) {
        num = nums[i];
        tmp[i][0] = num;
        tmp[i][1] = sumDigits(num);
    }
    
    qsort(tmp, numsSize, sizeof(int *), compare);
    
    for (i = 0, lastIndex = numsSize-1; i < lastIndex; ) {
        if (tmp[i][1] == tmp[i+1][1]) {
            sum = tmp[i][0] + tmp[i+1][0];
            max = (max > sum) ? max : sum;
            
            while (i < lastIndex && tmp[i][1] == tmp[i+1][1]) {
                ++i;
            }
            ++i;
        } else {
            ++i;
        }
    }
    
    free(tmp);
    return max;
}
