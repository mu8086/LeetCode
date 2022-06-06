#define QUEEN           'Q'
#define SEEN            1
#define NEVER_SEEN      -10
#define INVALID         NEVER_SEEN
#define MAX_BOARDS_SIZE 1000

typedef struct {
    char ***boards;
    int boardsSize;
    int boardSize;
} Ans;

typedef struct {
    int x;
    int y;
} P;

typedef struct {
    int boardSize;
    int *slash;       // i+j: 0               ~ (boardSize-1)*2
    int *back_slash;  // i-j: -(boardSize-1)  ~ boardSize-1
    int *x;           //      0               ~ boardSize-1
    int *y;           //      0               ~ boardSize-1
} Board;

char **char2dArray(int length, int width) {
    // ret[width][length]
    char **ret = (char **) malloc(sizeof(char *) * width + sizeof(char) * width * length);
    char *first = (char*)(ret + width);
    memset(first, '.', sizeof(char) * width * length);

    for (int i=0; i<width; ++i) {
        ret[i] = first + i * length;
        ret[i][length-1] = '\0';
    }

    return ret;
}

char ***char3dArray(int length, int width, int height) {
    // ret[height][width][length]
    char ***ret = (char ***) malloc(sizeof(char **) * height + sizeof(char *) * height * width + sizeof(char) * height * width * length);

    char **first_row = (char **)(ret + height);
    char *first      = (char *)(first_row + height * width);
    //memset(first, 0, sizeof(char) * height * width * length);

    for (int i=0, j, wl = width * length; i<height; ++i) {
        ret[i] = first_row + i * width;
        
        ret[i][0] = first + i * wl;
        ret[i][0][length-1] = '\0';
        for (j=1; j<width; ++j) {
            ret[i][j] = ret[i][j-1] + length;
            ret[i][j][length-1] = '\0';
        }
    }

    return ret;
}

// n = boardSize = count of Queens
char ** makeQueensBoard(int n, P *p) {
    // the '+1' is for string ending '\0'
    char **board = char2dArray(n + 1, n);

    while (--n >= 0) {
        board[ p[n].x ][ p[n].y ] = QUEEN;
    }

    return board;
}

int* getReturnColumnSizes(int row, int colVal) {
    int* returnColumnSizes = (int*) malloc(sizeof(int) * 1 * row);
    
    for (int i=0; i<row; i++) {
        returnColumnSizes[i] = colVal;
    }

    return returnColumnSizes;
}

char ***copiedAns(Ans ans, int *returnSize, int **returnColumnSizes) {
    char ***copiedBoards = NULL;
    
    *returnSize = ans.boardsSize;

    if (ans.boardsSize == 0) {
        *returnColumnSizes = getReturnColumnSizes(1, ans.boardsSize);
    } else {
        *returnColumnSizes = getReturnColumnSizes(*returnSize, ans.boardSize);
        
        // length = ans.boardSize + 1, the '+1' is for string ending '\0' 
        copiedBoards = char3dArray(ans.boardSize + 1, ans.boardSize, ans.boardsSize);
        // only copy all char
        memcpy(&copiedBoards[0][0][0], &ans.boards[0][0][0], sizeof(char) * (ans.boardSize + 1) * ans.boardSize * ans.boardsSize);
    }

    return copiedBoards;
}

void resetBoard(Board *board) {
    for (int *tmp = board->y + board->boardSize - 1; tmp >= board->slash; --tmp) {
        *tmp = NEVER_SEEN;
    }
}

Board * newBoard(int boardSize) {
    Board *board        = (Board *) malloc(sizeof(Board) + (sizeof(int) * (boardSize * 6 - 2)));

    board->boardSize    = boardSize;
    board->slash        = (int *)(board + 1);
    board->back_slash   = board->slash  + (boardSize * 2 - 1) + (boardSize - 1);
    board->x            = board->slash  + (boardSize * 2 - 1) * 2;
    board->y            = board->x      + boardSize;

    resetBoard(board);

    return board;
}

void freeBoard(Board *board) {
	  free(board);
}

P * newP(int boardSize) {
    P *p = (P *) malloc(sizeof(P) * boardSize);
    
    for (int i=0; i<boardSize; ++i) {
        p[i].x = p[i].y = NEVER_SEEN;
    }
    
    return p;
}

void freeP(P *p) {
    free(p);
}

int getNextValidYForQueenIndex(int x, Board *board, int boardSize, int ori_y) {
    int y = (ori_y != INVALID) ? ori_y+1 : 0;
    
    while (y < boardSize) {
        if (board->slash[x+y] == NEVER_SEEN &&
            board->back_slash[x-y] == NEVER_SEEN &&
            board->y[y] == NEVER_SEEN) {
            return y;
        }
        ++y;
    }
    
    return INVALID;
}

void resetIndexP(Board *board, P p[], int p_index) {
    int x = p[p_index].x, y = p[p_index].y;
    
    if (x != NEVER_SEEN) {
        board->slash[x+y]       = NEVER_SEEN;
        board->back_slash[x-y]  = NEVER_SEEN;
        board->x[x]             = NEVER_SEEN;
        board->y[y]             = NEVER_SEEN;
        p[p_index].x            = NEVER_SEEN;
        p[p_index].y            = NEVER_SEEN;
    }
}

void setIndexP(Board *board, P p[], int p_index, int y) {
    int x = p_index;
    
    board->slash[x+y]       = SEEN;
    board->back_slash[x-y]  = SEEN;
    board->x[x]             = SEEN;
    board->y[y]             = SEEN;
    
    p[p_index].x = x;
    p[p_index].y = y;
}

void findQueens(int queen_index, Board *board, int boardSize, P p[boardSize], Ans *ans) {
    if (queen_index == boardSize) {
        char **tmp = makeQueensBoard(boardSize, p);
        ans->boards[(ans->boardsSize)++] = tmp;
    } else {
        int y = INVALID;

        while (true) {
            resetIndexP(board, p, queen_index);
            
            y = getNextValidYForQueenIndex(queen_index, board, boardSize, y);
            if (y == INVALID) {
                break;
            }
            
            setIndexP(board, p, queen_index, y);
        
            findQueens(queen_index+1, board, boardSize, p, ans);
        }
    }
}

Ans _solveNQueens(int boardSize) {
    Ans ans = { .boards = NULL, .boardsSize = 0, .boardSize = boardSize };
    
    if (boardSize == 1) {
        ans.boardsSize = 1;
        ans.boards = char3dArray(boardSize + 1, boardSize, ans.boardsSize);
        ans.boards[0][0][0] = QUEEN;
    } else if (boardSize >= 4) {
        Board *board = newBoard(boardSize);
        P *p = newP(boardSize);
        
        char ***tmp = (char ***) malloc(sizeof(char **) * MAX_BOARDS_SIZE);
        ans.boards = tmp;
        findQueens(0, board, board->boardSize, p, &ans);
        
        ans.boards = char3dArray(ans.boardSize + 1, ans.boardSize, ans.boardsSize);
        for (int i=0; i<ans.boardsSize; ++i) {
            memcpy(ans.boards[i][0], tmp[i] + ans.boardSize, sizeof(char) * ans.boardSize * (ans.boardSize+1));
        }
        
        free(tmp);
        freeP(p);
        freeBoard(board);
    }
    
    return ans;
}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    static bool once = false;
    static Ans ans[9] = {};
    
    if (!once) {
        once = true;

        for (int i=1; i<=9; ++i) {
            ans[i-1] = _solveNQueens(i);
        }
    }

    return copiedAns(ans[n-1], returnSize, returnColumnSizes);
}
