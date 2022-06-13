#define MAX_VALUE   2000000

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int i, j, colSize, min;
    
    for (i = 1; i < triangleSize; ++i) {
        triangle[i][0] += triangle[i-1][0];
        for (j = 1, colSize = triangleColSize[i]-1; j < colSize; ++j) {
            triangle[i][j] += (triangle[i-1][j-1] < triangle[i-1][j])
                                ? triangle[i-1][j-1] : triangle[i-1][j];
        }
        triangle[i][colSize] += triangle[i-1][colSize-1];
    }
    
    for (i = triangleSize-1, j = 0, colSize = triangleColSize[i], min = MAX_VALUE; j < colSize; ++j) {
        min = (min < triangle[i][j]) ? min : triangle[i][j];
    }
    
    return min;
}
