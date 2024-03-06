char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) {
        char *s = malloc(sizeof(char));
        s[0] = '\0';
        return s;
    }

    if (strsSize == 1) {
        return strs[0];
    }
    
    int s1_len = strlen(strs[0]);
    
    for (int i=0; i<s1_len; i++) {
        for (int str=1; str<strsSize; str++) {
            if (strs[str][i] != strs[0][i]) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }
    
    return strs[0];
}
