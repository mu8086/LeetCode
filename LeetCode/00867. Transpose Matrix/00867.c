int ** int2dArray(int m, int n) {
    int **arr = (int **) malloc(sizeof(int *) * m + sizeof(int) * m * n);
    memset(arr, 0, sizeof(int *) * m + sizeof(int) * m * n);
    
    int i, *first_int = (int *)(arr + m);
    
    for (i=0; i<m; ++i) {
        arr[i] = first_int + i * n;
    }
    
    return arr;
}

int * getReturnColumnSizes(int row, int col) {
    int i, *ret = (int *) malloc(sizeof(int) * 1 * row);
    
    for (i=0; i<row; ++i) {
        ret[i] = col;
    }
    
    return ret;
}

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    int **ret = int2dArray(*matrixColSize, matrixSize);
    
    for (int i=0, j; i<matrixSize; ++i) {
        for (j=0; j<*matrixColSize; ++j) {
            ret[j][i] = matrix[i][j];
        }
    }
    
    *returnSize = *matrixColSize;
    *returnColumnSizes = getReturnColumnSizes(*matrixColSize, matrixSize);
    return ret;
}
