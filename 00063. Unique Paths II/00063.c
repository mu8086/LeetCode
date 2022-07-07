#define CLEAR       0
#define OBSTACLE    1

int uniquePathsWithObstacles(int** grid, int gridSize, int* gridColSize) {
    int i, j;
    int last_row = gridSize-1, last_col = (*gridColSize)-1;

    if (grid[0][0] == OBSTACLE || grid[last_row][last_col] == OBSTACLE) {
        return 0;
    }
    
    for (i=0; i<=last_row && grid[i][0] == CLEAR; i++) {
        grid[i][0] = -1;
    }
    
    for (i=1; i<=last_col && grid[0][i] == CLEAR; i++) {
        grid[0][i] = -1;
    }
    
    for (i=1; i<=last_row; i++) {
        for (j=1; j<=last_col; j++) {
            if (grid[i][j] == CLEAR) {
                if (grid[i-1][j] != OBSTACLE) {
                    grid[i][j] += grid[i-1][j];
                }
                if (grid[i][j-1] != OBSTACLE) {
                    grid[i][j] += grid[i][j-1];
                }
            }
        }
    }
    
    return -(grid[last_row][last_col]);
}
