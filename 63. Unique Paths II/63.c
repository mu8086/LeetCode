#define CLEAR    0
#define OBSTACLE 1

struct P {
    int row;
    int col;
};

bool isEmptyQueue(int index, int size) {
    return index == size;
}

void enQueue(struct P queue[], int* size, struct P node) {
    queue[(*size)++] = node;
}

void deQueueAll(struct P queue[], int* index, int* size, int** grid, int gridSize, int gridColSize) {
    int row, col, old_size;
    static struct P node = {};

    for (old_size=*size; *index<old_size; (*index)++) {
        row = queue[*index].row;
        col = queue[*index].col;

        if (grid[row][col] == CLEAR) {
            if (row-1 >= 0 && grid[row-1][col] < 0) {
                grid[row][col] += grid[row-1][col];
            }
            if (col-1 >= 0 && grid[row][col-1] < 0) {
                grid[row][col] += grid[row][col-1];
            }
        
            if (row+1 < gridSize && grid[row+1][col] == CLEAR) {
                node.row = row+1, node.col = col;
                enQueue(queue, size, node);
            }
            if (col+1 < gridColSize && grid[row][col+1] == CLEAR) {
                node.row = row, node.col = col+1;
                enQueue(queue, size, node);
            }
        }
    }
}

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int last_row = obstacleGridSize-1;
    int last_col = (*obstacleGridColSize)-1;
    
    if (obstacleGrid[0][0] == OBSTACLE || obstacleGrid[last_row][last_col] == OBSTACLE) {
        return 0;
    }
    
    int index = 0, size = 0;
    obstacleGrid[0][0] = -1;
    struct P queue[10000] = {};
    if (obstacleGridSize > 1) {
        queue[size].row = 1;
        queue[size++].col = 0;
    }
    if (*obstacleGridColSize > 1) {
        queue[size].row = 0;
        queue[size++].col = 1;
    }
    
    while (!isEmptyQueue(index, size) && obstacleGrid[last_row][last_col] == CLEAR) {
        deQueueAll(queue, &index, &size, obstacleGrid, obstacleGridSize, *obstacleGridColSize);
    }

    return -(obstacleGrid[last_row][last_col]);
}
