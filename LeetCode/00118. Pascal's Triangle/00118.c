#define MAX_ROW 30

int ** generate(int numRows, int *returnSize, int **returnColumnSizes) {
    static bool once = false;
    static int **ret = NULL, *columnSizes = NULL;
    
    if (once == false) {
        once = true;
        
        ret = (int **) malloc(sizeof(int *) * MAX_ROW);
        columnSizes = (int *) malloc(sizeof(int) * MAX_ROW);
        
        for (int i = 0, j; i < MAX_ROW; ++i) {
            columnSizes[i] = i+1;
            ret[i] = (int *) malloc(sizeof(int) * (i+1));
            ret[i][0] = ret[i][i] = 1;
            for (j = i-1; j > 0; --j) {
                ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
            }
        }
    }
    
    *returnSize = numRows;
    *returnColumnSizes = columnSizes;
    return ret;
}
