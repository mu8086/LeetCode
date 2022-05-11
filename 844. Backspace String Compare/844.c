char* getReverseValidStr(char* s, int len) {
    char* reverse = (char*) malloc(sizeof(char) * (len+1));
    memset(reverse, 0, sizeof(char) * (len+1));

    for (int i=len-1, len_rev=0, count=0; i>=0; i--) {
        if (s[i] != '#') {
            if (count != 0) {
                count--;
                continue;
            }
            reverse[len_rev++] = s[i];
        } else {
            count++;
        }
    }
    
    return reverse;
}

bool backspaceCompare(char * s, char * t){
    bool ret = false;
    char* ss = getReverseValidStr(s, strlen(s));
    char* tt = getReverseValidStr(t, strlen(t));
    
    if (strlen(ss) == strlen(tt)) {
        ret = !memcmp(ss, tt, sizeof(char) * (strlen(ss)+1));
    }
    free(ss);
    free(tt);
    return ret;
}
