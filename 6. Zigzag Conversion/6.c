char * convert(char * s, int numRows) {
    int second_target, s_len = strlen(s), numRows_1 = numRows-1, window_size = numRows_1*2;
    int s_index = 0;
    char * tmp = malloc(sizeof(char) * (s_len+1));
    memcpy(tmp, s, s_len);

    if (numRows == 1)
        return s;

    for (int i=0; i<numRows; i++) {
        if (i == 0 || i == numRows_1)
            second_target = -1;
        else
            second_target = numRows_1*2-i;

        for (int window=0; window<s_len; window+=window_size) {
            if (window+i<s_len) {
                s[s_index] = tmp[window+i];
                s_index++;
            }
            if (second_target != -1 && window+second_target<s_len) {
                s[s_index] = tmp[window+second_target];
                s_index++;
            }
        }
    }

    free(tmp);
    return s;
}
