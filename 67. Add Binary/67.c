int max(int a, int b) {
    return a > b ? a : b;
}

void reverse(char* s, int len) {
    char tmp;
    
    for (int i=len/2-1; i>=0; i--) {
        tmp = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = tmp;
    }
}

void addChar0(char* s, int len) {
    for (int i=len-1, flag=0; i>=0; i--) {
        if (flag == 0 && s[i] != 0) {
            flag = 1;
        }
        if (flag == 1) {
            s[i] += '0';
        }
    }
}

char * addBinary(char * a, char * b){
    int len_a = strlen(a), len_b = strlen(b);
    if (len_a == 1 && a[0] == '0') {
        return b;
    } else if (len_b == 1 && b[0] == '0') {
        return a;
    }
    
    int len_ret = max(len_a, len_b) + 2;
    char* ret = (char*) malloc(sizeof(char) * len_ret);
    memset(ret, 0, sizeof(char) * len_ret);
    
    reverse(a, len_a);
    reverse(b, len_b);

    for (int i=0; i<len_ret; i++) {
        if (i < len_a) {
            ret[i] += a[i] - '0';
        }
        if (i < len_b) {
            ret[i] += b[i] - '0';
        }
        if (ret[i] > 1) {
            ret[i+1]++;
            ret[i] -= 2;
        }
    }
    
    addChar0(ret, len_ret);
    reverse(ret, strlen(ret));
    
    return ret;
}
