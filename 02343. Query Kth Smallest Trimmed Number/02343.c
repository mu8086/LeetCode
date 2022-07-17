struct myNode {
    int index;
    char * num;
};

int startDigit = 0;

int compare(const void *aa, const void *bb) {
    struct myNode a = *(const struct myNode *)aa;
    struct myNode b = *(const struct myNode *)bb;

    int strcmpRes = strcmp(&(a.num[startDigit]), &(b.num[startDigit]));
    
    if (strcmpRes == 0) {
        return a.index - b.index;
    }
    return strcmpRes;
}

int* smallestTrimmedNumbers(char ** nums, int numsSize, int **queries, int queriesSize, int *queriesColSize, int *returnSize) {
    int i, numLen;
    int *ret = (int *) malloc(sizeof(int) * queriesSize);
    struct myNode node[100] = {};

    for (i = 0; i < numsSize; ++i) {
        node[i].index = i;
        node[i].num = nums[i];
    }
    
    for (i = 0, numLen = strlen(nums[0]); i < queriesSize; ++i) {
        startDigit = numLen - queries[i][1];
        qsort(node, numsSize, sizeof(struct myNode), compare);
        
        ret[i] = node[queries[i][0]-1].index;
    }

    *returnSize = queriesSize;
    return ret;
}
