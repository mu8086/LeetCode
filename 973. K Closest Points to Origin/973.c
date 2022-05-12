

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** array = NULL;
int* row1 = NULL;

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

bool compare(const void* a, const void* b) {
    int distance_a = getDistance(((int*)a)[0], ((int*)a)[1]);
    int distance_b = getDistance(((int*)b)[0], ((int*)b)[1]);
    printf(" ");    // without printf in compare function, then WA, no idea why
    return distance_a > distance_b;
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes){
    *returnSize = k;
    *returnColumnSizes = getReturnColumnSizes(*returnSize, *pointsColSize);
    
    if (k == pointsSize) {
        return points;
    }

    int** points2 = int2dArray(pointsSize, *pointsColSize);

    for (int i=0, j; i<pointsSize; i++) {
        for (j=0; j<*pointsColSize; j++) {
            points2[i][j] = points[i][j];
        }
    }
    points = points2;
    
    qsort(points+pointsSize, pointsSize, sizeof(int)*2, compare);

    return points;
}
