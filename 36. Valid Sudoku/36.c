bool isValidCol(char** board, int boardSize, int col) {
    char tmp[9] = {};

    for (int i=0; i<boardSize; i++) {
        if (board[i][col] == '.') {
            continue;
        }
        
        if (tmp[board[i][col] - '1'] == '\0') {
            tmp[board[i][col] - '1'] = board[i][col];
        } else {
            return false;
        }
    }

    return true;
}

bool isValidRow(char** board, int boardSize, int row) {
    char tmp[9] = {};

    for (int j=0; j<boardSize; j++) {
        if (board[row][j] == '.') {
            continue;
        }
        
        if (tmp[board[row][j] - '1'] == '\0') {
            tmp[board[row][j] - '1'] = board[row][j];
        } else {
            return false;
        }
    }

    return true;
}

bool isValidGrid(char** board, int grid) {
    int gridLeftIndex = (grid % 3) * 3;
    int gridTopIndex = (grid / 3) * 3;
    char tmp[9] = {};

    for (int i=gridTopIndex+2; i>=gridTopIndex; i--) {
        for (int j=gridLeftIndex+2; j>=gridLeftIndex; j--) {
            if (board[i][j] == '.') {
                continue;
            }
            
            if (tmp[board[i][j] - '1'] == '\0') {
                tmp[board[i][j] - '1'] = board[i][j];
            } else {
                return false;
            }
        }
    }

    return true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    for (int i=0; i< 9; i++) {
        if (!isValidRow(board, boardSize, i) || \
            !isValidCol(board, boardSize, i) || \
            !isValidGrid(board, i)) {
            return false;
        }
    }
    
    return true;
}
