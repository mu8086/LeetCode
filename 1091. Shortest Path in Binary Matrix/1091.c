#define CLEAR_POINT 0
#define QUEUE_SIZE 10000

struct Node {
    int row;
    int col;
};

bool isEmptyQueue(int index, int size) {
    return index == size;
}

int setNeighbor(struct Node node, struct Node neighbor[], int boundary) {
    int row, col, size = 0;
    
    for (row=node.row-1; row<=node.row+1; row++) {
        if (row == -1 || row == boundary) {
            continue;
        }
        for (col=node.col-1; col<=node.col+1; col++) {
            if (col == -1 || col == boundary) {
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

void deQueueAll(int** grid, int gridSize, struct Node queue[], int* queueIndex, int* queueSize) {
    int sameLevelNodeSize = *queueSize - *queueIndex;
    int neighborSize, neighborRow, neighborCol;
    struct Node node, neighbor[8] = {};
    
    for (int i=0, j; i<sameLevelNodeSize; i++) {
        node = queue[(*queueIndex)++];
        neighborSize = setNeighbor(node, neighbor, gridSize);
        
        for (j=0; j<neighborSize; j++) {
            neighborRow = neighbor[j].row, neighborCol = neighbor[j].col;
            if (grid[neighborRow][neighborCol] == CLEAR_POINT) {
                grid[neighborRow][neighborCol] = grid[node.row][node.col]-1;
                enQueue(queue, neighbor[j], queueSize);
            }
        }
    }
}

int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize){
    int ret = -1;
    int last_index = gridSize-1;

    if (grid[0][0] == CLEAR_POINT && grid[last_index][last_index] == CLEAR_POINT) {
        grid[0][0] = -1;
        
        int beginQueueIndex = 0, beginQueueSize = 1;
        struct Node beginQueue[QUEUE_SIZE] = {{.row=0, .col=0}};
    
        while (!isEmptyQueue(beginQueueIndex, beginQueueSize)) {
            deQueueAll(grid, gridSize, beginQueue, &beginQueueIndex, &beginQueueSize);
            if (grid[last_index][last_index] != CLEAR_POINT) {
                break;
            }
        }
    
        ret = (grid[last_index][last_index] != CLEAR_POINT) ? grid[last_index][last_index] * -1 : -1;
    }
    
    return ret;
}
