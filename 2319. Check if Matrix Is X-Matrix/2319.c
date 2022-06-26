bool checkXMatrix(int** grid, int gridSize, int *gridColSize) {
    int i, j;
    int row = gridSize, col = *gridColSize, tmp = gridSize-1;
    
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            if (i == j || i+j == tmp) {
                if (grid[i][j] == 0) {
                    return false;
                }
            } else {
                if (grid[i][j] != 0) {
                    return false;
                }
            }
        }
    }
    
    return true;
}
