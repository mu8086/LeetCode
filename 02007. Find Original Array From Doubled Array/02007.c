#define NOT_FOUND   -1

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int searchIndex(int *changed, bool *visited, int begin, int end, int targetVal) {
    int midIdx, midVal;
    
    while (begin <= end) {
        midIdx = (begin + end) / 2;
        midVal = changed[midIdx];
        
        if (midVal == targetVal) {
            if (visited[midIdx] == false) {
                if (midIdx+1 <= end && changed[midIdx+1] == targetVal && visited[midIdx+1] == false) {
                    begin = midIdx+1;
                    continue;
                }
                return midIdx;
            } else {
                end = midIdx-1;
            }
        } else if (midVal < targetVal) {
            begin = midIdx+1;
        } else {
            end = midIdx-1;
        }
    }
    
    return NOT_FOUND;
}

int * findOriginalArray(int *changed, int changedSize, int *returnSize) {
    if (changedSize & 1) {
        *returnSize = 0;
        return NULL;
    }
    
    *returnSize = changedSize / 2;
    int *ret = (int *) malloc(sizeof(int) * *returnSize);
    
    bool *visited = (bool *) malloc(sizeof(bool) * changedSize);
    memset(visited, 0, sizeof(bool) * changedSize);
    
    qsort(changed, changedSize, sizeof(int), compare);
    
    for (int i = 0, retIdx = 0, lastI = changedSize-1, doubledIdx; i <= lastI; ++i) {
        if (visited[i] == false) {
            if ((doubledIdx = searchIndex(changed, visited, i+1, lastI, changed[i] * 2)) == NOT_FOUND) {
                free(visited);
                free(ret);
                *returnSize = 0;
                return NULL;
            } else {
                ret[retIdx++] = changed[i];
                visited[doubledIdx] = true;
            }
        }
    }
    
    free(visited);
    return ret;
}
