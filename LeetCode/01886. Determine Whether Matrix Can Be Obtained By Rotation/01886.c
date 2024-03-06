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

void rotate(int** mat, int rowSize) {
    func(mat, 0, 0, rowSize);
}

bool isSameMatrix(int** a, int** b, int rowSize, int colSize) {
    for (int i=0, j; i<rowSize; i++) {
        for (j=0; j<colSize; j++) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize){
    if (isSameMatrix(mat, target, matSize, *matColSize)) {
        return true;
    }
    
    for (int i=1; i<=3; i++) {
        rotate(mat, matSize);
        
        if (isSameMatrix(mat, target, matSize, *matColSize)) {
            return true;
        }
    }
    
    return false;
}
