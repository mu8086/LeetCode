// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

char * removeDuplicates(char * s){
    int i, idx_s, len = strlen(s);
    char *ans = (char *) malloc(sizeof(char) * (len+1));
    memset(ans, 0, sizeof(char) * (len+1));

    for (idx_s = 0, i = -1; idx_s < len; ++idx_s) {
        if (i < 0 || ans[i] != s[idx_s]) {
            ans[++i] = s[idx_s];
        } else {
            ans[i] = '\0';
            --i;
        }
    }

    return ans;
}
