bool isArithmeticArray(int* array, int subSize) {
    int diff=array[1]-array[0], i;
        
    for (i=2; i<subSize; i++) {
        if (array[i-1] + diff != array[i]) {
            return false;
        }
    }
    
    return true;
}

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize){
    *returnSize = lSize;
    bool* ret = (bool*) malloc(sizeof(bool) * *returnSize);
    memset(ret, 0, sizeof(bool) * *returnSize);
    
    int* subArray = (int*) malloc(sizeof(int) * numsSize);
    memset(subArray, 0, sizeof(int) * numsSize);
    
    int i, j, m=lSize, subSize;
    for (i=0; i<m; i++) {
        subSize = r[i]-l[i]+1;
        if (subSize != 2) {
            memcpy(subArray, &nums[l[i]], sizeof(int) * subSize);
            qsort(subArray, subSize, sizeof(int), compare);
            
            ret[i] = isArithmeticArray(subArray, subSize);
        } else {
            ret[i] = true;
        }
    }

    free(subArray);
    return ret;
}
