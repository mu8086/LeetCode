int ** int2dArray(int row, int col) {
    int size = sizeof(int *) * row + sizeof(int) * row * col;
    int **ret = (int **) malloc(size);
    memset(ret, 0, size);

    int *first = (int *)(ret + row);
    for (int i=0; i<row; ++i) {
        ret[i] = first + i * col;
    }

    return ret;
}

int longestCommonSubsequence(char* text1, char *text2) {
    int ans = 0;
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    int **map = int2dArray(len1+1, len2+1);

    for (int i=0, j, tmp; i<len1; ++i) {
        for (j=0; j<len2; ++j) {
            if (text1[i] == text2[j]) {
                map[i+1][j+1] = map[i][j]+1;
            } else {
                tmp = fmax(map[i][j], map[i+1][j]);
                map[i+1][j+1] = fmax(tmp, map[i][j+1]);
            }
        }
    }

    ans = map[len1][len2];
    free(map);
    return ans;
}
