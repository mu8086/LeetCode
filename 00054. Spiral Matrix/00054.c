#define RIGHT   0
#define DOWN    1
#define LEFT    2
#define UP      3

bool isRightValid(bool met[][10], int row, int col, int matrixColSize) {
    return col+1 < matrixColSize && met[row][col+1] == false;
}

bool isDownValid(bool met[][10], int row, int col, int matrixSize) {
    return row+1 < matrixSize && met[row+1][col] == false;
}

bool isLeftValid(bool met[][10], int row, int col) {
    return col-1 >= 0 && met[row][col-1] == false;
}

bool isUpValid(bool met[][10], int row, int col) {
    return row-1 >= 0 && met[row-1][col] == false;
}

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    *returnSize = matrixSize * *matrixColSize;
    
    bool met[10][10] = {};
    int i, row, col, direction;
    int* ret = (int*) malloc(sizeof(int) * *returnSize);
    
    for (i=row=col=0, direction=RIGHT; i<*returnSize; i++) {
        ret[i] = matrix[row][col];
        met[row][col] = true;
        
        if (direction == RIGHT) {
            if (isRightValid(met, row, col, *matrixColSize)) {
                col++;
            } else {
                direction = DOWN;
                row++;
            }
        } else if (direction == DOWN) {
            if (isDownValid(met, row, col, matrixSize)) {
                row++;
            } else {
                direction = LEFT;
                col--;
            }
        } else if (direction == LEFT) {
            if (isLeftValid(met, row, col)) {
                col--;
            } else {
                direction = UP;
                row--;
            }
        } else if (direction == UP) {
            if (isUpValid(met, row, col)) {
                row--;
            } else {
                direction = RIGHT;
                col++;
            }
        }
    }
    
    return ret;
}
