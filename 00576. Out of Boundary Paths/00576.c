#define M 1000000007

int ** int2dArray(int m, int n) {
    int **ret = (int**) malloc(sizeof(int *) * m + sizeof(int) * m * n);
    memset(ret, 0, sizeof(int *) * m + sizeof(int) * m * n);

    int *first_int = (int *)(ret + m);
    for (int i = 0; i < m; ++i) {
        ret[i] = first_int + i * n;
    }
    
    return ret;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    int i, j, count, moves;
    int **dp    = int2dArray(m, n);
    int **newDp = int2dArray(m, n);
    int dpNumsSize = sizeof(int) * m * n;
    
    dp[startRow][startColumn] = 1;
    
    for (moves = 1, count = 0; moves <= maxMove; ++moves) {
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                // 4 ways out
                if (i == 0)     count = (count + dp[i][j]) % M;
                if (i == m-1)   count = (count + dp[i][j]) % M;
                if (j == 0)     count = (count + dp[i][j]) % M;
                if (j == n-1)   count = (count + dp[i][j]) % M;
                
                newDp[i][j] = (
                        ((i > 0 ? dp[i-1][j] : 0) + (i < m-1 ? dp[i+1][j] : 0)) % M +
                        ((j > 0 ? dp[i][j-1] : 0) + (j < n-1 ? dp[i][j+1] : 0)) % M
                ) % M;
            }
        }
        memcpy(dp + m, newDp + m, dpNumsSize);
        memset(newDp + m, 0, dpNumsSize);
    }
    
    free(dp);
    free(newDp);
    return count;
}
