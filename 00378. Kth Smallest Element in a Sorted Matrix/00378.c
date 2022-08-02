#define MAX_NODE    90000

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int kthSmallest(int **matrix, int matrixSize, int *matrixColSize, int k) {
    int arr[MAX_NODE] = {};
    
    for (int i = 0, size = sizeof(int) * matrixSize; i < matrixSize; ++i) {
        memcpy(&arr[i * matrixSize], matrix[i], size);
    }
    
    qsort(arr, matrixSize * matrixSize, sizeof(int), compare);

    return arr[k-1];
}
