bool ** bool2dArray(int m, int n) {
    bool *first_element, **ret = (bool **) malloc(sizeof(bool *) * m + sizeof(bool) * m * n);
    memset(ret, 0, sizeof(bool *) * m + sizeof(bool) * m * n);
    
    first_element = (bool *)(ret + m);
    for (int i=0; i<m; ++i) {
        ret[i] = first_element + i * n;
    }
    
    return ret;
}

void matchChar(bool **table, char *s1, char *s2, char c3, int row, int col) {
    if (table[row][col-1] == true && s2[col-1] == c3) {
        table[row][col] = true;
    } else if (table[row-1][col] == true && s1[row-1] == c3) {
        table[row][col] = true;
    }
}

bool isInterleave(char * s1, char * s2, char * s3) {
    int i, j;
    int len_1 = strlen(s1), len_2 = strlen(s2), len_3 = strlen(s3);
    if (len_1 + len_2 != len_3) {
        return false;
    } else if (len_3 == 0) {
        return true;
    } else if (len_1 == 0) {
        return !memcmp(s2, s3, len_3);
    } else if (len_2 == 0) {
        return !memcmp(s1, s3, len_3);
    }
    
    bool ret, **table = bool2dArray(len_1+1, len_2+1);
    
    table[0][0] = true;
    for (i=0; i<len_1; ++i) {
        table[i+1][0] = (table[i][0] == true && s1[i] == s3[i]);
    }
    
    for (i=0; i<len_2; ++i) {
        table[0][i+1] = (table[0][i] == true && s2[i] == s3[i]);
    }
    
    for (i=1; i<=len_1; ++i) {
        for (j=1; j<=len_2; ++j) {
            matchChar(table, s1, s2, s3[i+j-1], i, j);
        }
    }
    
    ret = table[len_1][len_2];
    free(table);
    return ret;
}
