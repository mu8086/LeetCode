void setAns(int n, int *ans[], int size[]) {
    int mySize = size[n];
    int lastSize = size[n-1];
    int tmp = size[n-1];
    
    for (int i = 0, j = mySize-1; i < lastSize; ++i, --j) {
        ans[n][i] = ans[n-1][i];
        ans[n][j] = ans[n-1][i] + tmp;
    }
}

void getAns(int n, int *ans[], int size[]) {
    ans[n] = (int *) malloc(sizeof(int) * size[n]);
        
    if (n == 0) {
        ans[n][0] = 0, ans[n][1] = 1;
    } else {
        getAns(n-1, ans, size);
        setAns(n, ans, size);
    }
}

int * grayCode(int n, int * returnSize) {
    if (n < 1 || n > 16) {
        *returnSize = 0;
        return NULL;
    }
    
    static int *ans[16] = {};
    static int size[16] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};
    
    if (ans[15] == NULL) {
        getAns(15, ans, size);
    }
    
    *returnSize = size[n-1];
    return ans[n-1];
}
