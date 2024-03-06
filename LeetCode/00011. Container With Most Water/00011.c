int ** int2dArray(int row, int col) {
    int **ret = (int **) malloc(sizeof(int *) * row + sizeof(int) * row * col);
    int *first = (int *)(ret + row);
    
    for (int i = 0; i < row; ++i) {
        ret[i] = first + i * col;
    }
    
    return ret;
}

int compare(const void *aa, const void *bb) {
    int *a = *(int **)aa, *b = *(int **)bb;
    return *b - *a;
}

int maxArea(int *height, int heightSize) {
    int i, left, right, max = 0;
    int h, idx, sum;
    int **map = int2dArray(heightSize, 2);  // map[i][0]: height, map[i][1] = idx
    
    for (i = 0; i < heightSize; ++i) {
        map[i][0] = height[i];
        map[i][1] = i;
    }
    
    qsort(map, heightSize, sizeof(int) * 2, compare);
    
    left = right = map[0][1];
    for (i = 1; i < heightSize; ++i) {
        h = map[i][0];
        idx = map[i][1];

        if (left > idx) {
            left = idx;
        }
        if (right < idx) {
            right = idx;
        }
        
        sum = h * fmax(idx - left, right - idx);
        if (max < sum) {
            max = sum;
        }
    }
    
    free(map);
    return max;
}
