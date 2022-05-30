int minPathSum(int** grid, int gridSize, int* gridColSize){
    int row, col, last_row=gridSize-1, last_col=(*gridColSize)-1;
    
    for (col=1; col<=last_col; ++col) {
        grid[0][col] += grid[0][col-1];
    }
    
    for (row=1; row<=last_row; ++row) {
        grid[row][0] += grid[row-1][0];
        
        for (col=1; col<=last_col; ++col) {
            grid[row][col] += \
                (grid[row-1][col] < grid[row][col-1]) \
                    ? grid[row-1][col] : grid[row][col-1];
        }
    }

    return grid[last_row][last_col];
}
