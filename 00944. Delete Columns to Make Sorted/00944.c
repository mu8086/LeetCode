// https://leetcode.com/problems/delete-columns-to-make-sorted

int minDeletionSize(char ** strs, int size) {
    int i, j, remove = 0;
    int len = strlen(strs[0]);

    for (j = 0; j < len; ++j) {
        for (i = 1; i < size; ++ i) {
            if (strs[i][j] < strs[i-1][j]) {
                ++remove;
                break;
            }
        }
    }

    return remove;
}
