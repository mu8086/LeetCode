void rotate_edge(int **matrix, int start_row, int start_col, int matrixSize) {
    int i, tmp, *n[4] = {};
    int end_row = start_row + matrixSize - 1;
    int end_col = start_col + matrixSize - 1;
    
    for (i = matrixSize-2; i >= 0; --i) {
        n[0] = &matrix[end_row-i][start_col];   // bottom left
        n[1] = &matrix[end_row][end_col-i];     // bottom right
        n[2] = &matrix[start_row+i][end_col];   // top right
        n[3] = &matrix[start_row][start_col+i]; // top left
        
        tmp = *(n[0]);
        *(n[0]) = *(n[1]);
        *(n[1]) = *(n[2]);
        *(n[2]) = *(n[3]);
        *(n[3]) = tmp;
    }
}

void rotate(int **matrix, int matrixSize, int *matrixColSize) {
    for (int i = matrixSize/2 - 1; i >= 0; --i) {
        rotate_edge(matrix, i, i, matrixSize-i-i);
    }
}
