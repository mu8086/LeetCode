void reverse(char *s, int begin, int end) {
    for (int i = 0, half = (end-begin) >> 1, tmp; i <= half; ++i) {
        tmp         = s[begin+i];
        s[begin+i]  = s[end-i];
        s[end-i]    = tmp;
    }
}

char * reverseStr(char *s, int k) {
    if (k > 1) {
        int i, len = strlen(s);

        for (i = 0; i+k <= len; i = i+k+k) {
            reverse(s, i, i+k-1);
        }
        if (i < len) {
            reverse(s, i, len-1);
        }
    }

    return s;
}
