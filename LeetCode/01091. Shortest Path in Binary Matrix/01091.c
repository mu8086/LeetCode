#define CLEAR_POINT 0
#define DIRTY_POINT 1
#define QUEUE_SIZE 10000
#define NO_CLEAR_PATH -1

struct Node {
    int row;
    int col;
};

bool isEmptyQueue(int index, int size) {
    return index == size;
}

int setNeighbor(struct Node node, struct Node neighbor[], int rowSize, int colSize) {
    int row, col, size = 0;
    
    for (row=node.row-1; row<=node.row+1; row++) {
        if (row == -1 || row == rowSize) {
            continue;
        }
        for (col=node.col-1; col<=node.col+1; col++) {
            if (col == -1 || col == colSize) {
                continue;
            }
            if (row == node.row && col == node.col) {
                continue;
            }
            neighbor[size].row = row, neighbor[size].col = col;
            size++;
        }
    }
    
    return size;
}

void enQueue(struct Node queue[], struct Node node, int* size) {
    queue[(*size)++] = node;
}

int deQueueAll(int** grid, int rowSize, int colSize, struct Node queue[], int* queueIndex, int* queueSize) {
    int sameLevelNodeSize = *queueSize - *queueIndex;
    int neighborSize, neighborRow, neighborCol;
    struct Node node, neighbor[8] = {};
    
    for (int i=0, j; i<sameLevelNodeSize; i++) {
        node = queue[(*queueIndex)++];
        neighborSize = setNeighbor(node, neighbor, rowSize, colSize);
        
        for (j=0; j<neighborSize; j++) {
            neighborRow = neighbor[j].row, neighborCol = neighbor[j].col;
            if (grid[neighborRow][neighborCol] == CLEAR_POINT) {    // my queue next step
                grid[neighborRow][neighborCol] = grid[node.row][node.col]-2;
                enQueue(queue, neighbor[j], queueSize);
            } else if (grid[neighborRow][neighborCol] != DIRTY_POINT && \
                       (grid[neighborRow][neighborCol]-grid[node.row][node.col]) % 2 != 0) {    // meet another queue
                return (grid[neighborRow][neighborCol]-1 + grid[node.row][node.col]-1) * -1 / 2;
            }
        }
    }
    
    return NO_CLEAR_PATH;
}

int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize){
    int ret = NO_CLEAR_PATH;
    int last_row = gridSize - 1;
    int last_col = *gridColSize - 1;

    if (gridSize == 1 && *gridColSize == 1) {
        return 1;
    }
    
    if (grid[0][0] == CLEAR_POINT && grid[last_row][last_col] == CLEAR_POINT) {
        grid[0][0] = -1;
        int beginQueueIndex = 0, beginQueueSize = 1;
        struct Node beginQueue[QUEUE_SIZE] = {{.row=0, .col=0}};
        
        grid[last_row][last_col] = -2;
        int endQueueIndex = 0, endQueueSize = 1;
        struct Node endQueue[QUEUE_SIZE] = {{.row=last_row, .col=last_col}};
    
        while (true) {
            if (!isEmptyQueue(beginQueueIndex, beginQueueSize)) {
                ret = deQueueAll(grid, gridSize, *gridColSize, beginQueue, &beginQueueIndex, &beginQueueSize);
                if (ret != NO_CLEAR_PATH) {
                   break;
                }
            } else {
                break;
            }
            
            if (!isEmptyQueue(endQueueIndex, endQueueSize)) {
                ret = deQueueAll(grid, gridSize, *gridColSize, endQueue, &endQueueIndex, &endQueueSize);
                if (ret != NO_CLEAR_PATH) {
                   break;
                }
            } else {
                break;
            }
        }
    }
    
    return ret;
}
