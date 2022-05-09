bool isZero(char * num) {
    return num[1] == '\0' && num[0] == '0';
}

void reverse(char * s, int len_s) {
    int last_index = len_s - 1;
    int half_len_s = len_s / 2;
    char tmp;
    for (int i=0; i<half_len_s; i++) {
        tmp = s[i];
        s[i] = s[last_index-i];
        s[last_index-i] = tmp;
    }
}

void subChar0(char* s, int len_s) {
    for (int i=0; i<len_s; i++) {
        s[i] -= '0';
    }
}

void addChar0(char* s, int len_s) {
    for (int i=len_s-1, flag=0; i>=0; i--) {
        if (s[i] != 0) {
            flag = 1;
        }
        if (flag == 1) {
            s[i] += '0';
        }
    }
}

char * multiply(char * num1, char * num2){
    if (isZero(num1))       return num1;
    else if (isZero(num2))  return num2;

    int len_1 = strlen(num1), len_2 = strlen(num2);
    int len_ret = len_1 + len_2 + 1;
    char* ret = (char*) malloc(sizeof(char) * len_ret);
    memset(ret, 0, len_ret);
    
    reverse(num1, len_1);
    reverse(num2, len_2);
    
    subChar0(num1, len_1);
    subChar0(num2, len_2);
    
    int i, j;
    for (i=0; i<len_1; i++) {
        for (j=0; j<len_2; j++) {
            ret[i+j] += (num1[i] * num2[j]);
            if (ret[i+j] > 9) {
                ret[i+j+1] += ret[i+j] / 10;
                ret[i+j] %= 10;
            }
        }
    }

    addChar0(ret, len_ret);
    reverse(ret, strlen(ret));

    return ret;
}
