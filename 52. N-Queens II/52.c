#define SEEN            true
#define NEVER_SEEN      false
#define INVALID         -10

typedef struct {
    int x;
    int y;
} P;

typedef struct {
    int boardSize;
    bool *slash;       // i+j: 0               ~ (boardSize-1)*2
    bool *back_slash;  // i-j: -(boardSize-1)  ~ boardSize-1
    bool *x;           //      0               ~ boardSize-1
    bool *y;           //      0               ~ boardSize-1
} Board;

Board * newBoard(int boardSize) {
    Board *board        = (Board *) malloc(sizeof(Board) + (sizeof(bool) * (boardSize * 6 - 2)));

    board->boardSize    = boardSize;
    board->slash        = (bool *)(board + 1);
    board->back_slash   = board->slash  + (boardSize * 2 - 1) + (boardSize - 1);
    board->x            = board->slash  + (boardSize * 2 - 1) * 2;
    board->y            = board->x      + boardSize;

    memset(board->slash, NEVER_SEEN, sizeof(bool) * (board->boardSize * 6 - 2));

    return board;
}

void freeBoard(Board *board) {
    free(board);
}

P * newP(int boardSize) {
    P *p = (P *) malloc(sizeof(P) * boardSize);
    
    for (int i=0; i<boardSize; ++i) {
        p[i].x = p[i].y = INVALID;
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
    
    if (x != INVALID) {
        board->slash[x+y]       = NEVER_SEEN;
        board->back_slash[x-y]  = NEVER_SEEN;
        board->x[x]             = NEVER_SEEN;
        board->y[y]             = NEVER_SEEN;
        p[p_index].x            = INVALID;
        p[p_index].y            = INVALID;
    }
}

void setIndexP(Board *board, P p[], int p_index, int y) {
    int x = p_index;
    
    board->slash[x+y]       = SEEN;
    board->back_slash[x-y]  = SEEN;
    board->x[x]             = SEEN;
    board->y[y]             = SEEN;
    p[p_index].x            = x;
    p[p_index].y            = y;
}

void findQueens(int queen_index, Board *board, int boardSize, P p[boardSize], int *ans) {
    if (queen_index == boardSize) {
        ++(*ans);
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

int solveNQueens(int boardSize) {
    int count = 0;
    
    if (boardSize == 1) {
        count = 1;
    } else if (boardSize >= 4) {
        Board *board = newBoard(boardSize);
        P *p = newP(boardSize);
        
        findQueens(0, board, board->boardSize, p, &count);

        freeP(p);
        freeBoard(board);
    }
    
    return count;
}

int totalNQueens(int n) {
    static bool once = false;
    static int ans[9] = {};
    
    if (!once) {
        once = true;
        
        for (int i=1; i<=9; ++i) {
            ans[i-1] = solveNQueens(i);
        }
    }

    return ans[n-1];
}
