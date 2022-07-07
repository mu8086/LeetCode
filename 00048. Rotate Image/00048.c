void func(int** matrix, int start_row, int start_col, int matrixSize) {
    if (matrixSize < 2) {
        return;
    }
    
    int* n[4] = {};
    int end_row = start_row + matrixSize - 1;
    int end_col = start_col + matrixSize - 1;
    
    for (int i=0, tmp; i<matrixSize-1; i++) {
        n[0] = &matrix[end_row-i][start_col];
        n[1] = &matrix[end_row][end_col-i];
        n[2] = &matrix[start_row+i][end_col];
        n[3] = &matrix[start_row][start_col+i];
        tmp = *(n[0]);
        *(n[0]) = *(n[1]);
        *(n[1]) = *(n[2]);
        *(n[2]) = *(n[3]);
        *(n[3]) = tmp;
    }
    
    func(matrix, start_row+1, start_col+1, matrixSize-2);
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    func(matrix, 0, 0, matrixSize);
}
