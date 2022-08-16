#define CHAR_SIZE   255

int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

char * frequencySort(char *s) {
    int i, len = strlen(s);
    int feqSize = CHAR_SIZE;
    int feq[CHAR_SIZE][2] = {}; // feq[i][0]: appear times, feq[i][1]: the char
    
    int retIndex;
    char c, *ret = (char *) malloc(sizeof(char) * (len + 1));
    
    for (i = 0; i < len; ++i) {
        c = s[i];
        ++(feq[c][0]);
        feq[c][1] = c;
    }
    
    qsort(feq, CHAR_SIZE, sizeof(int) * 2, compare);
    
    for (i = 0, retIndex = 0; i < feqSize; ++i) {
        if (feq[i][0] == 0) {
            break;
        }
        
        c = feq[i][1];

        while (--feq[i][0] >= 0) {
            ret[retIndex++] = c;
        }
    }
    
    ret[retIndex++] = '\0';
    
    return ret;
}
