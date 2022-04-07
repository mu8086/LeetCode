int lengthOfLongestSubstring(char * s){
    int index[256] = {0};
    int i, max_len, curr_len, head_index;
    
    if (s[0] == '\0') {
        return 0;
    } else if (s[1] == '\0') {
        return 1;
    }
    
    for (i=1, max_len=1, head_index=0; s[i] != '\0'; i++) {
        if (index[s[i]] == 0 && s[0] != s[i]) {
            // first met this char in whole string s
            index[s[i]] = i;
        } else if (index[s[i]] < head_index) {
            // first met this char in this substring
            index[s[i]] = i;
        } else {
            // found the same char in this substring
            curr_len = i - head_index;
            if (max_len < curr_len)
                max_len = curr_len;
            
            head_index = index[s[i]] + 1;
            index[s[i]] = i;
        }
    }
    curr_len = i - head_index;
    if (max_len < curr_len)
        max_len = curr_len;
    
    return max_len;
}
