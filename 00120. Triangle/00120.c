int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int i, j, colSize, left, right;
    
    for (i = triangleSize-2; i >= 0; --i) {
        for (j = 0, colSize = triangleColSize[i]; j < colSize; ++j) {
            left  = triangle[i+1][j];
            right = triangle[i+1][j+1];
            triangle[i][j] += (left < right) ? left : right;
        }
    }
    
    return triangle[0][0];
}
