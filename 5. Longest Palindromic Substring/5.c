int lastTarget(char *s, int target_index, int start_index) {
    char target = s[target_index];
    for (int i=start_index; i>target_index; i--) {
        if (s[i] == target)
            return i;
    }
    return -1;  // not found
}

int isPalindrome(char *s, int start_index, int end_index) {
    for (int i=start_index, j=end_index; i<j; i++, j--) {
        if (s[i] != s[j])
            return 0;   // not
    }
    
    return 1;   // yes
}

char * longestPalindrome(char * s) {
    int len[1000]={1};
    int i, j, max_len=0, index_of_max=0, s_len=strlen(s);
    
    if (s_len < 2)
        return s;
    
    for (i=0; i<s_len; i++) {
        for (j=lastTarget(s, i, s_len-1); j!=-1; j=lastTarget(s, i, j)) {
            if (isPalindrome(s, i, j)) {
                len[i] = j-i+1;
                break;
            }
            j--;
        }
        
        if (max_len < len[i]) {
            max_len = len[i];
            index_of_max = i;
        }
    }
    
    s[index_of_max + len[index_of_max]] = '\0';
    return &s[index_of_max];
}
