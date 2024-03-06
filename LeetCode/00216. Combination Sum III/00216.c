bool isValid(int start_num, int k, int n) {
    if (n < 3 || 45 < n) {  // all-set minimum (1+2=3), maximum (1+2+3+...+9=45)
        return false;
    } else if (9 < start_num+k-1) {
        return false;
    }
    int n2 = n*2;
    return (start_num+(start_num+k-1))*k <= n2 && n2 <= ((9-k+1)+9)*k;  // n must between minimun and maximum
}

void copyBufToRet(int buf[], int len_b, int** ret, int* returnSize) {
    memcpy(ret[*returnSize], buf, sizeof(int) * len_b);
}

void func(int buf[], int index_b, int start_num, int left_k, int left_n, int** ret, int* returnSize) {
    if (left_k == 1 && start_num <= left_n && left_n <= 9) {
        buf[index_b] = left_n;
        copyBufToRet(buf, index_b+1, ret, returnSize);
        (*returnSize)++;
        return;
    }
    
    for (int i=start_num; i<=9; i++) {
        buf[index_b] = i;
        if (isValid(i+1, left_k-1, left_n-i)) {
            func(buf, index_b+1, i+1, left_k-1, left_n-i, ret, returnSize);
        }
    }
}

int** int2dArray(int row, int column) {
    int **ret = (int**) malloc(sizeof(int*) * row + sizeof(int) * row * column);
    
    for (int i=0; i<row; i++) {
        ret[i] = (int*) (ret+row) + i * column;
    }
    
    return ret;
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
    int** ret = int2dArray(15, 9);
    
    *returnSize = 0;
    if (isValid(1, k, n)) {
        int buf[9] = {};
        func(buf, 0, 1, k, n, ret, returnSize);
    }
    
    if (*returnSize > 0) {
        *returnColumnSizes = (int*) malloc(sizeof(int) * *returnSize);
        for (int i=0; i<*returnSize; i++) {
            returnColumnSizes[0][i] = k;
        }
    }

    return ret;
}
