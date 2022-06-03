typedef struct {
    int ** sum;
    int row;
    int col;
} NumMatrix;

int ** int2dArray(int m, int n) {
    int **arr = (int **) malloc(sizeof(int*) * m + sizeof(int) * m * n);
    
    int i, *first_element = (int *)(arr + m);
    
    for (i=0; i<m; ++i) {
        arr[i] = first_element + i * n;
    }
    
    return arr;
}

NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    int i, j, row = matrixSize, col = *matrixColSize;
    int **sum = int2dArray(row, col);
    //int **sum = matrix;  // in place for speed up
    
    sum[0][0] = matrix[0][0];
    for (i=1; i<col; ++i) {
        sum[0][i] = sum[0][i-1] + matrix[0][i];
    }

    for (i=1; i<row; ++i) {
        sum[i][0] = sum[i-1][0] + matrix[i][0];
        for (j=1; j<col; ++j) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i][j];
        }
    }
    
    NumMatrix *numMatrix = (NumMatrix *) malloc(sizeof(NumMatrix));
    numMatrix->sum = sum;
    numMatrix->row = row;
    numMatrix->col = col;
    return numMatrix;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    int left, upper, inner, **sum = obj->sum;
    
    upper   = (row1 != 0)               ? sum[row1-1][col2]     : 0;
    left    = (col1 != 0)               ? sum[row2][col1-1]     : 0;
    inner   = (row1 != 0 && col1 != 0)  ? sum[row1-1][col1-1]   : 0;
    
    return sum[row2][col2] - upper - left + inner;
}

void numMatrixFree(NumMatrix* obj) {
    if (obj != NULL) {
        free(obj->sum);
        free(obj);
    }
}
