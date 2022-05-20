#define OBSTACLE 1

int func(int** grid, int gridSize, int gridColSize, int to_row, int to_col) {
    if (to_row >= gridSize || to_col >= gridColSize) {
        return 0;
    } else if (grid[to_row][to_col] == OBSTACLE) {
        return 0;
    } else if (to_row == gridSize-1 && to_col == gridColSize-1) {
        return 1;
    } else {
        return func(grid, gridSize, gridColSize, to_row+1, to_col) + func(grid, gridSize, gridColSize, to_row, to_col+1);
    }
}

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    if (obstacleGrid[0][0] == OBSTACLE || obstacleGrid[obstacleGridSize-1][(*obstacleGridColSize)-1] == OBSTACLE) {
        return 0;
    }
    if (obstacleGridSize == 1 && *obstacleGridColSize == 1) {
        return (obstacleGrid[0][0] == OBSTACLE) ? 0 : 1;
    }
    return func(obstacleGrid, obstacleGridSize, *obstacleGridColSize, 0, 1) + func(obstacleGrid, obstacleGridSize, *obstacleGridColSize, 1, 0);
}
