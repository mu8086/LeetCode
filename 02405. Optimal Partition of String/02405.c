#define CHAR_SIZE   255

int partitionString(char * s) {
    int i, times, head, len = strlen(s);
    int index[CHAR_SIZE] = {};
    memset(index, -1, sizeof(int) * CHAR_SIZE);
    
    for (i = 0, times = 1, head = 0; i < len; ++i) {
        if (index[s[i]] >= head) {
            head = i;
            ++times;
        }
        index[s[i]] = i;
    }
    
    return times;
}
