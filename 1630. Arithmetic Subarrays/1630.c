bool isArithmeticArray(int* array, int arraySize) {
    int diff=array[1]-array[0], i;
        
    for (i=2; i<arraySize; i++) {
        if (array[i] - array[i-1] != diff) {
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
    int* subArray = (int*) malloc(sizeof(int) * numsSize);
    
    int i, j, ll, m=lSize, subSize;
    for (i=0; i<m; i++) {
        ll = l[i];
        subSize = r[i]-ll+1;
        if (subSize != 2) {
            memcpy(subArray, nums+ll, sizeof(int) * subSize);
            qsort(subArray, subSize, sizeof(int), compare);
            
            ret[i] = isArithmeticArray(subArray, subSize);
        } else {
            ret[i] = true;
        }
    }

    free(subArray);
    return ret;
}
