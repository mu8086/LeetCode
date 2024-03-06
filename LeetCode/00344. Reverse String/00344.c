void reverseString(char *s, int sSize) {
    for (int i = sSize/2-1, lastIdx = sSize-1, tmp; i >= 0; --i) {
        tmp             = s[i];
        s[i]            = s[lastIdx-i];
        s[lastIdx-i]    = tmp;
    }
}
