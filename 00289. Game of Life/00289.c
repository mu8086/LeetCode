#define DEAD    0
#define LIVE    1

bool isLive(int **board, int rowSize, int colSize, int row, int col) {
    if (row < 0 || row >= rowSize || col < 0 || col >= colSize) {
        return false;
    }
    return board[row][col] & 1;
}

int getLiveNeighbors(int **board, int rowSize, int colSize, int row, int col) {
    int i, j, lastI, lastJ;
    int sum = (board[row][col] & 1) ? -1 : 0;

    for (i = row-1, lastI = row+1; i <= lastI; ++i) {
        for (j = col-1, lastJ = col+1; j <= lastJ; ++j) {
            if (isLive(board, rowSize, colSize, i, j)) {
                ++sum;
            }
        }
    }

    return sum;
}

void gameOfLife(int **board, int boardSize, int *boardColSize) {
    int i, j, neighbors, newState;
    int col = *boardColSize;

    for (i = 0; i < boardSize; ++i) {
        for (j = 0; j < col; ++j) {
            neighbors = getLiveNeighbors(board, boardSize, col, i, j);

            if (board[i][j] & 1) {
                newState = (neighbors == 2 || neighbors == 3) ? LIVE : DEAD;
            } else {
                newState = (neighbors == 3) ? LIVE : DEAD;
            }

            board[i][j] |= newState << 1;
        }
    }

    for (i = 0; i < boardSize; ++i) {
        for (j = 0; j < col; ++j) {
            board[i][j] >>= 1;
        }
    }
}
