int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize){
    *returnSize = temperaturesSize;
    int* ret = (int*) malloc(sizeof(int) * *returnSize);
    memset(ret, 0, sizeof(int) * *returnSize);
    
    for (int i=temperaturesSize-2; i>=0; i--) {
        if (temperatures[i] < temperatures[i+1]) {
            ret[i] = 1;
        } else if (temperatures[i] == temperatures[i+1]) {
            ret[i] = (ret[i+1] == 0) ? 0 : ret[i+1]+1;
        } else {
            for (int j=i+2; j<temperaturesSize; j++) {
                if (temperatures[i] < temperatures[j]) {
                    ret[i] = j-i;
                    break;
                } else if (temperatures[i] == temperatures[j]) {
                    ret[i] = (ret[j] == 0) ? 0 : ret[j]+j-i;
                    break;
                }
            }
        }
    }

    return ret;
}
