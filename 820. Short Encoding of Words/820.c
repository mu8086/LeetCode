int compare(const void *a, const void *b) {
    const char *aa = *(const char **)a;
    const char *bb = *(const char **)b;
    return -strcmp(aa, bb);
}

void reverse(char *s) {
    int i, lastI = strlen(s) - 1;
    char tmp;
    
    for (i = lastI/2; i >= 0; i--) {
        tmp         = s[i];
        s[i]        = s[lastI-i];
        s[lastI-i]  = tmp;
    }
}

void reverseAll(char **words, int wordsSize) {
    for (int i = 0; i < wordsSize; ++i) {
        reverse(words[i]);
    }
}

int minimumLengthEncoding(char ** words, int wordsSize) {
    int i, ret, len, longWordLen, longWordIndex;
    
    // reverse all words, then sort in reverse order
    reverseAll(words, wordsSize);
    qsort(words, wordsSize, sizeof(char *), compare);
    
    longWordIndex   = 0;
    longWordLen     = strlen(words[0]);
    ret             = longWordLen + 1;

    for (i = 1; i < wordsSize; ++i) {
        len = strlen(words[i]);

        if (len > longWordLen || strncmp(words[longWordIndex], words[i], len) != 0) {
            longWordLen     = len;
            longWordIndex   = i;
            ret             = ret + len + 1;
        }
    }

    return ret;
}
