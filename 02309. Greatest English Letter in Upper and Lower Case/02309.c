char * greatestLetter(char * s) {
    int c[256] = {};
    int i, len_s, range = 'a' - 'A';
    char *ret = (char *) malloc(sizeof(char) * 2);
    ret[0] = ret[1] = '\0';
    
    for (i = 0, len_s = strlen(s); i < len_s; ++i) {
        c[s[i]]++;
    }
    
    for (i = 'z'; i >= 'a'; --i) {
        if (c[i] != 0 && c[i-range] != 0) {
            ret[0] = i-range;
            break;
        }
    }
    
    return ret;
}
