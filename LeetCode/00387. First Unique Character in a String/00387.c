#define ALPHABET_SIZE   26

int firstUniqChar(char *s) {
    int i, len;
    int feq[ALPHABET_SIZE] = {};
    
    for (i = 0, len = strlen(s); i < len; ++i) {
        ++feq[s[i] - 'a'];
    }
    
    for (i = 0; i < len; ++i) {
        if (feq[s[i] - 'a'] == 1) {
            return i;
        }
    }
    
    return -1;
}
