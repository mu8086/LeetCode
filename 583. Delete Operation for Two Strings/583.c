#define MAX_LEN 500

int minDistance(char * word1, char * word2) {
    int lcs, i, j, left, up;
    int len_1 = strlen(word1), len_2 = strlen(word2);
    
    if (len_1 == 0 || len_2 == 0) {
        return len_1 + len_2;
    }

    int dp[MAX_LEN+1][MAX_LEN+1] = {};
    
    for (i = 1; i <= len_1; ++i) {
        for (j = 1; j <= len_2; ++j) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j]    = dp[i-1][j-1] + 1;
            } else {
                up          = dp[i-1][j];
                left        = dp[i][j-1];
                dp[i][j]    = (up > left) ? up : left;
            }
        }
    }
    
    lcs = dp[len_1][len_2];
    return len_1 + len_2 - lcs * 2;
}
