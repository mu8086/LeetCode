#define NOT_FOUND   -1
#define MAX_SIZE    200001

int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int * findOriginalArray(int *changed, int changedSize, int *returnSize) {
    if (changedSize & 1) {
        *returnSize = 0;
        return NULL;
    }
    
    *returnSize = changedSize / 2;
    int i, retIdx, n;
    int *ret = (int *) malloc(sizeof(int) * *returnSize);
    int freq[MAX_SIZE] = {};
    
    qsort(changed, changedSize, sizeof(int), compare);
    
    for (i = 0; i < changedSize; ++i) {
        ++freq[changed[i]];
    }
    
    for (i = changedSize-1, retIdx = 0; i >= 0; --i) {
        n = changed[i];
        
        if (freq[n] > 0) {
            if (freq[n << 1] == 0) {
                *returnSize = 0;
                free(ret);
                ret = NULL;
                break;
            } else {
                // corner case: freq[0*2] --> -1, but
                // [1] changedSize must be even number
                // [2] freq[changed[i]] must be paired
                // so if it happens, there is a number meet the above 'if' statement
                // then return NULL
                --freq[n];
                if (--freq[n << 1] < 0) {
                    *returnSize = 0;
                    free(ret);
                    ret = NULL;
                    break;
                }
                ret[retIdx++] = n;
            }
        }
    }
    
    return ret;
}
