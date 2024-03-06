int ** int2dArray(int row, int col) {
    int **ret = (int **) malloc(sizeof(int *) * row + sizeof(int) * row * col);
    int *first = (int *)(ret + row);

    for (int i = 0; i < row; ++i) {
        ret[i] = first + i * col;
    }

    return ret;
}

int** generateMatrix(int n, int *returnSize, int ** returnColumnSizes) {
    int **ret = int2dArray(n, n);
    int i, j, num, rowBegin = 0, rowEnd = n-1, colBegin = 0, colEnd = n-1;

    *returnSize = n;
    *returnColumnSizes = (int *) malloc(sizeof(int) * n);
    for (i = 0; i < n; ++i) {
        (*returnColumnSizes)[i] = n;
    }

    n *= n;
    num = 1;
    while (num <= n) {
        for (i = rowBegin, j = colBegin; j <= colEnd; ++j) {
            ret[i][j] = num++;
        }
        ++rowBegin;

        for (i = rowBegin, j = colEnd; i <= rowEnd; ++i) {
            ret[i][j] = num++;
        }
        --colEnd;

        for (i = rowEnd, j = colEnd; j >= colBegin; --j) {
            ret[i][j] = num++;
        }
        --rowEnd;

        for (i = rowEnd, j = colBegin; i >= rowBegin; --i) {
            ret[i][j] = num++;
        }
        ++colBegin;
    }

    return ret;
}
