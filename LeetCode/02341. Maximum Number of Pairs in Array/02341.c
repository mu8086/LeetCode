int * numberOfPairs(int *nums, int numsSize, int *returnSize) {
    int *ret = (int *) malloc(sizeof(int) * 2);
    ret[0] = ret[1] = 0;
  
    int *visited = (int *) malloc(sizeof(int) * numsSize);
    memset(visited, 0, sizeof(int) * numsSize);
    *returnSize = 2;
    
    for (int i = 0, j, num; i < numsSize; ++i) {
        if (visited[i] == 0) {
            num = nums[i];
            for (j = i+1; j < numsSize; ++j) {
                if (visited[j] == 0 && num == nums[j]) {
                    visited[i] = visited[j] = 1;
                    ++ret[0];
                    break;
                }
            }
        }
    }
    
    ret[1] = numsSize - 2 * ret[0];
    free(visited);
    return ret;
}
