int **int2dArray(int m, int n) {
    int** ret = (int**) malloc(sizeof(int*) * m + sizeof(int) * m * n);
    memset(ret, 0, sizeof(int*) * m + sizeof(int) * m * n);

    int* first_int = (int*)(ret + m);
    for (int i=0; i<m; i++) {
        ret[i] = first_int + i * n;
    }
    
    return ret;
}

int uniquePaths(int m, int n){
    int **arr = int2dArray(m, n);
    int ret, row, col;
    
    for (col=0; col<n; col++) {
        arr[0][col] = 1;
    }
    
    for (row=1; row<m; row++) {
        arr[row][0] = 1;
        for (col=1; col<n; col++) {
            arr[row][col] = arr[row-1][col] + arr[row][col-1];
        }
    }
    
    ret = arr[m-1][n-1];
    
    free(arr);
    return ret;
}
