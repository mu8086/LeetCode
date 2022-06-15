int ** int2dArray(int m, int n) {
    int **ret = (int **) malloc(sizeof(int *) * m + sizeof(int) * m * n);

    int *first_int = (int *)(ret + m);
    for (int i = 0; i < m; i++) {
        ret[i] = first_int + i * n;
    }
    memset(first_int, 0, sizeof(int) * m * n);
    
    return ret;
}

int getStep(int **steps, int **matrix, int lastRow, int lastCol, int rowIndex, int colIndex) {
    if (steps[rowIndex][colIndex] == 0) {
        int up = 0, down = 0, left = 0, right = 0, max;

        if (rowIndex > 0 && matrix[rowIndex][colIndex] > matrix[rowIndex-1][colIndex]) {
            up = getStep(steps, matrix, lastRow, lastCol, rowIndex-1, colIndex);
        }
        if (rowIndex < lastRow && matrix[rowIndex][colIndex] > matrix[rowIndex+1][colIndex]) {
            down = getStep(steps, matrix, lastRow, lastCol, rowIndex+1, colIndex);
        }
        if (colIndex > 0 && matrix[rowIndex][colIndex] > matrix[rowIndex][colIndex-1]) {
            left = getStep(steps, matrix, lastRow, lastCol, rowIndex, colIndex-1);
        }
        if (colIndex < lastCol && matrix[rowIndex][colIndex] > matrix[rowIndex][colIndex+1]) {
            right = getStep(steps, matrix, lastRow, lastCol, rowIndex, colIndex+1);
        }

        max = (up > down) ? up : down;
        max = (max > left) ? max : left;
        max = (max > right) ? max : right;

        steps[rowIndex][colIndex] = max + 1;
    }
    return steps[rowIndex][colIndex];
}

int longestIncreasingPath(int **matrix, int matrixSize, int *matrixColSize) {
    int i, j, max, tmp, lastRow = matrixSize-1, lastCol = *matrixColSize-1;
    int **steps = int2dArray(matrixSize, *matrixColSize);
    
    for (i = 0, max = 0; i <= lastRow; ++i) {
        for (j = 0; j <= lastCol; ++j) {
            tmp = getStep(steps, matrix, lastRow, lastCol, i, j);
            max = (max > tmp) ? max : tmp;
        }
    }

    free(steps);
    return max;
}
