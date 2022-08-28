int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int ** diagonalSort(int **mat, int matSize, int *matColSize, int *returnSize, int **returnColumnSizes) {
    int i, j, k;
    int row = matSize, col = *matColSize;
    int tmpIndex, tmpSize = (row < col) ? row : col;
    int *tmp = (int *) malloc(sizeof(int) * tmpSize);
    
    // each diagonal line
    for (k = -(row-1); k < col; ++k) {
        i = (k >= 0) ? 0 : -k;
        j = (k >= 0) ? k : 0;
        for (tmpIndex = 0; i < row && j < col; ++i, ++j) {
            tmp[tmpIndex++] = mat[i][j];
        }
        
        qsort(tmp, tmpIndex, sizeof(int), compare);
        
        i = (k >= 0) ? 0 : -k;
        j = (k >= 0) ? k : 0;
        for (tmpIndex = 0; i < row && j < col; ++i, ++j) {
            mat[i][j] = tmp[tmpIndex++];
        }
    }
    
    free(tmp);
    
    *returnSize = row;
    *returnColumnSizes = (int *) malloc(sizeof(int) * row);
    for (i = 0; i < row; ++i) {
        (*returnColumnSizes)[i] = col;
    }
    return mat;
}
