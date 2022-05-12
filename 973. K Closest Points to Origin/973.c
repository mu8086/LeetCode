int* getReturnColumnSizes(int row, int col) {
    int* returnColumnSizes = (int*) malloc(sizeof(int) * 1 * row);
    
    for (int i=0; i<row; i++) {
        returnColumnSizes[i] = col;
    }

    return returnColumnSizes;
}

int** int2dArray(int m, int n) {
    int** ret = (int**) malloc(sizeof(int*) * m + sizeof(int) * m * n);
    memset(ret, 0, sizeof(int*) * m + sizeof(int) * m * n);

    int* first_int = (int*)(ret + m);
    for (int i=0; i<m; i++) {
        ret[i] = first_int + i * n;
    }
    
    return ret;
}

int getDistance(int x, int y) {
    return x*x + y*y;
}

int** getDistancesAndIndex(int** points, int pointsSize) {
    int **distancesAndIndex = int2dArray(pointsSize, 2);
    
    for (int i=0; i<pointsSize; i++) {
        distancesAndIndex[i][0] = getDistance(points[i][0], points[i][1]);
        distancesAndIndex[i][1] = i;
    }
    
    return distancesAndIndex;
}

bool compare(const void* a, const void* b) {
    return *((int*) a) > *((int*) b);
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes){
    *returnSize = k;
    *returnColumnSizes = getReturnColumnSizes(*returnSize, *pointsColSize);
    
    if (k == pointsSize) {
        return points;
    }

    int** ret = int2dArray(k, 2);
    int** distancesAndIndex = getDistancesAndIndex(points, pointsSize);

    qsort(distancesAndIndex+pointsSize, pointsSize, sizeof(int) * 2, compare);
 
    for (int i=0; i<*returnSize; i++) {
        ret[i][0] = points[distancesAndIndex[i][1]][0];
        ret[i][1] = points[distancesAndIndex[i][1]][1];
    }
    
    free(distancesAndIndex);
    return ret;
}
