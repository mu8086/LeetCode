#define MAX_LENGTH  1000

int findLength(int *n1, int n1Size, int *n2, int n2Size) {
    int i, j;
    int tmpLength, maxLength = 0;
    int dp[MAX_LENGTH][MAX_LENGTH] = {};

    for (i = 0; i < n1Size; ++i) {
        if (n1[i] == n2[0]) {
            dp[i][0] = maxLength = 1;
        }
    }

    for (j = 0; j < n2Size; ++j) {
        if (n1[0] == n2[j]) {
            dp[0][j] = maxLength = 1;
        }
    }

    for (i = 1; i < n1Size; ++i) {
        for (j = 1; j < n2Size; ++j) {
            if (n1[i] == n2[j]) {
                dp[i][j] = tmpLength = dp[i-1][j-1] + 1;
                maxLength = (maxLength > tmpLength) ? maxLength : tmpLength;
            }
        }
    }

    return maxLength;
}
