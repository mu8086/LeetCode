int nextDifferentLetter(char *s, int k) {
    for (int i=1; i<k; i++) {
        if (s[0] != s[i])
            return i;
    }
    return k;
}

void strRemoveDuplicateKLetters(char* s, int k) {
    char tmp[100000] = {};
    memcpy(tmp, &s[k], strlen(&s[k]));
    memcpy(s, tmp, strlen(tmp)+1);
}

char * removeDuplicates(char * s, int k){
    int nextDifferent;
    
    for (int i=0, max_index=strlen(s)-k; i<=max_index; ) {
        nextDifferent = nextDifferentLetter(&s[i], k);
        if (nextDifferent == k) {
            strRemoveDuplicateKLetters(&s[i], k);
            max_index-=k;
            i=i-k+1;
            if (i<0) {
                i=0;
            }
        } else {
            i+=nextDifferent;
        }
    }
    
    return s;
} 
