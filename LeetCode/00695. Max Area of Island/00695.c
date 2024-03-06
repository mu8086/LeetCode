#define WATER   0
#define ISLAND  1
#define VISITED 2

void getArea(int **grid, int row, int col, int rowIndex, int colIndex, int *area) {
    if (rowIndex < 0 || rowIndex >= row || colIndex < 0 || colIndex >= col) {
        return;
    }
    
    if (grid[rowIndex][colIndex] == ISLAND) {
        grid[rowIndex][colIndex] = VISITED;
        ++(*area);
        
        getArea(grid, row, col, rowIndex,   colIndex-1, area);
        getArea(grid, row, col, rowIndex,   colIndex+1, area);
        getArea(grid, row, col, rowIndex-1, colIndex,   area);
        getArea(grid, row, col, rowIndex+1, colIndex,   area);
    }
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int max, area, i, j;
    int row = gridSize, col = *gridColSize;
    
    for (i = 0, max = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            if (grid[i][j] == ISLAND) {
                area = 0;
                getArea(grid, row, col, i, j, &area);
                max = (max > area) ? max : area;
            }
        }
    }
    
    return max;
}
