void helper(char **grid, int rowSize, int colSize, int row, int col) {
    if (row < 0 || col < 0 || row >= rowSize || col >= colSize) {
        return;
    }
 
    if (grid[row][col] == '1') {
        grid[row][col] = '0';
        helper(grid, rowSize, colSize, row-1, col);
        helper(grid, rowSize, colSize, row+1, col);
        helper(grid, rowSize, colSize, row, col-1);
        helper(grid, rowSize, colSize, row, col+1);
    }
}

int numIslands(char **grid, int gridSize, int *gridColSize) {
    int i, j, count;
    int rowSize = gridSize, colSize = *gridColSize;
    
    for (i = 0, count = 0; i < rowSize; ++i) {
        for (j = 0; j < colSize; ++j) {
            if (grid[i][j] == '1') {
                ++count;
                helper(grid, rowSize, colSize, i, j);
            }
        }
    }
    
    return count;
}
