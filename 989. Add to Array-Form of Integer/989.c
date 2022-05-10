int max(int a, int b) {
    return a > b ? a : b;
}

void reverse(int* arr, int len) {
    for (int i=len/2-1, tmp; i>=0; i--) {
        tmp = arr[i];
        arr[i] = arr[len-1-i];
        arr[len-1-i] = tmp;
    }
}

int* addToArrayForm(int* num, int numSize, int k, int* returnSize){
    int len_k = 5, i;
    int* numK = (int*) malloc(sizeof(int) * len_k);
    memset(numK, 0, sizeof(int) * len_k);
    
    for (i=0; i<len_k && k > 0; i++) {
        numK[i] = k % 10;
        k /= 10;
    }
    len_k = i;
    
    int len_ret = max(numSize, len_k) + 1;
    int* ret = (int*) malloc(sizeof(int) * len_ret);
    memset(ret, 0, sizeof(int) * len_ret);
    memcpy(ret, numK, sizeof(int) * len_k);
    
    reverse(num, numSize);

    for (i=0; i<len_ret; i++) {
        if (i<numSize) {
            ret[i] += num[i];
        }
        if (ret[i] > 9) {
            ret[i] -= 10;
            ret[i+1]++;
        }
    }
    
    if (ret[len_ret-1] == 0) {
        len_ret--;
    }
    reverse(ret, len_ret);
    
    *returnSize = len_ret;
    return ret;
}
