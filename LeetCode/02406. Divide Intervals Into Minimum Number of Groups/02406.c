#define POINT_SIZE 1000002

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int minGroups(int **intervals, int intervalsSize, int *intervalsColSize) {
    int i, j, max, carry;
    int point[POINT_SIZE] = {};
    
    int mapSize = intervalsSize * 2;
    int *map = (int *) malloc(sizeof(int) * mapSize);
    memset(map, 0, sizeof(int) * mapSize);
    
    for (i = 0, j = 0, max = 0; i < intervalsSize; ++i, j += 2) {
        ++point[intervals[i][0]];
        --point[intervals[i][1]+1];
        
        map[j] = intervals[i][0];
        map[j+1] = intervals[i][1]+1;
    }
    
    qsort(map, intervalsSize * 2, sizeof(int), compare);
    
    for (max = carry = point[map[0]], i = 1; i < mapSize; ++i) {
        if (map[i] != map[i-1]) {
            carry += point[map[i]];
            max = (max > carry) ? max : carry;
        }
    }
    
    free(map);
    return max;
}
