bool isValidCol(char** board, int boardSize, int col) {
    for (int i=0; i<boardSize; i++) {
        if (board[i][col] == '.') {
            continue;
        }
        
        for (int k=i+1; k<boardSize; k++) {
            if (board[i][col] == board[k][col]) {
                return false;
            }
        }
    }

    return true;
}

bool isValidRow(char** board, int boardSize, int row) {
    for (int j=0; j<boardSize; j++) {
        if (board[row][j] == '.') {
            continue;
        }
        
        for (int l=j+1; l<boardSize; l++) {
            if (board[row][j] == board[row][l]) {
                return false;
            }
        }
    }

    return true;
}

bool isValidGrid(char** board, int grid) {
    int gridLeftIndex = (grid % 3) * 3;
    int gridTopIndex = (grid / 3) * 3;

    int i, j, k, l;
    for (i=gridTopIndex+2; i>=gridTopIndex; i--) {
        for (j=gridLeftIndex+2; j>=gridLeftIndex; j--) {
            if (board[i][j] == '.') {
                continue;
            }
            
            for (k=i; k>=gridTopIndex; k--) {
                l = (k==i) ? j-1 : gridLeftIndex+2 ;
                for ( ; l>=gridLeftIndex; l--) {
                    if (board[i][j] == board[k][l]) {
                        return false;
                    }
                }
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
