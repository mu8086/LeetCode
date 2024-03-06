// https://leetcode.com/problems/minimum-falling-path-sum

int getMinUpper(int **m, int row, int col, int colSize) {
    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
    row = row-1; // last row

    if (0 <= col-1) {
        a = m[row][col-1];
    }
    if (0 <= col && col < colSize) {
        b = m[row][col];
    }
    if (col+1 < colSize) {
        c = m[row][col+1];
    }

    int min = fmin(a, b);
    return fmin(c, min);
}

int minFallingPathSum(int **matrix, int rowSize, int *matrixColSize) {
    int min = INT_MAX;
    int colSize=*matrixColSize;

    for (int row=1, col; row<rowSize; ++row) {
        for (col=0; col<colSize; ++col) {
            matrix[row][col] += getMinUpper(matrix, row, col, colSize);
        }
    }
    
    for (int row=rowSize-1, col=0; col<colSize; ++col) {
        if (min > matrix[row][col])
            min = matrix[row][col];
    }

    return min;
}
