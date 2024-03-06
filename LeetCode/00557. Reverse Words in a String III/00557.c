int getDelimiterIdx(char *s, int idx) {
    while (s[idx] != ' ' && s[idx] != '\0') {
        ++idx;
    }

    return idx;
}

void reverse(char * s, int begin, int end) {
    for (int i = 0, half = (end-begin) / 2, tmp; i <= half; ++i) {
        tmp = s[begin + i];
        s[begin + i] = s[end - i];
        s[end - i] = tmp;
    }
}

char * reverseWords(char *s) {
    for (int i = 0, len = strlen(s), delimiterIdx; i < len; i = delimiterIdx+1) {
        delimiterIdx = getDelimiterIdx(s, i);
        reverse(s, i, delimiterIdx-1);
    }

    return s;
}
