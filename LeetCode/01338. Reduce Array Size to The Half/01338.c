#define MAX_SIZE    100001

void setFeq(int feq[][2], int *arr, int arrSize) {
    for (int i = 0; i < arrSize; ++i) {
        ++(feq[arr[i]][0]);
        feq[arr[i]][1] = arr[i];
    }
}

int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int minSetSize(int *arr, int arrSize) {
    int i, feq[MAX_SIZE][2] = {};
    
    setFeq(feq, arr, arrSize);
    
    qsort(feq, MAX_SIZE, sizeof(int) * 2, compare);
    
    for (i = 0, arrSize/=2; arrSize > 0; ++i) {
        arrSize -= feq[i][0];
    }
    
    return i;
}
