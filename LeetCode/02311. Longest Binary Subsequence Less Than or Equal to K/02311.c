#define MAX_BIT_SIZE    32

void reverse(char kk[], int len) {
    char tmp;
    
    for (int i = 0, half = len / 2; i < half; ++i) {
        // swap
        tmp             = kk[i];
        kk[i]           = kk[len - 1 - i];
        kk[len - 1 - i] = tmp;
    }
}

int bitK(int k, char kk[]) {
    int bitSize;
    
    for (bitSize = 0; bitSize < MAX_BIT_SIZE && k > 0; ++bitSize, k /= 2) {
        kk[bitSize] = (k % 2) + '0';
    }
    
    reverse(kk, bitSize);
    
    return bitSize;
}

int leadingZeros(char *s, int len) {
    int i, count;
    
    for (i = 0, count = 0; i < len; ++i) {
        if (s[i] == '0') {
            ++count;
        }
    }
    
    return count;
}

int longestSubsequence(char * s, int k) {
    int i, j, len_kk;
    int ret = 0, len_s = strlen(s);
    
    static char kk[MAX_BIT_SIZE+1] = {};
    memset(kk, 0, sizeof(char) * (MAX_BIT_SIZE+1));
    
    len_kk = bitK(k, kk);
    
    if (len_s < len_kk) {
        return len_s;
    }
    
    bool found;
    
    for (j = len_s - len_kk; j >= 0; --j) {
        found = true;
        
        for (i = 0; i < len_kk; ++i) {
            if (kk[i] != s[j+i]) {
                found = (kk[i] > s[j+i]);
                break;
            }
        }
        if (found == true) {
            ret = len_kk + leadingZeros(s, j);
            break;
        }
    }
    
    return (ret != 0) ? ret : len_kk-1;
}
