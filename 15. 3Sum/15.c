#define MAX_RETURN_SIZE 20000

void addToRet(int **ret, int *returnSize, int *nums, int i, int j, int k) {
    int tmp = *returnSize;
    
    ret[tmp] = (int *) malloc(sizeof(int) * 3);
    ret[tmp][0] = nums[i], ret[tmp][1] = nums[j], ret[tmp][2] = nums[k];
    
    ++(*returnSize);
}

int ** getRet(int *nums, int numsSize, int *returnSize) {
    int i, j, k, max_i, lastIndex, sum;
    int **ret = (int **) malloc(sizeof(int *) * MAX_RETURN_SIZE);
    
    for (i = 0, max_i = numsSize-2, lastIndex = numsSize-1; i <= max_i; i++) {
        if (i != 0 && nums[i-1] == nums[i]) {
            continue;
        }
        
        for (j = i+1, k = lastIndex; j < k; ) {
            if (j != i+1 && nums[j-1] == nums[j]) {
                while (++j < k && nums[j-1] == nums[j]) {
                    ;
                }
                continue;
            }
            
            sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                addToRet(ret, returnSize, nums, i, j, k);
                while (++j < k && nums[j-1] == nums[j]) {
                    ;
                }
            } else if (sum > 0) {
                while (j < --k && nums[k] == nums[k+1]) {
                    ;
                }
            } else {
                while (++j < k && nums[j-1] == nums[j]) {
                    ;
                }
            }
        }
    }
    
    return ret;
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int * getReturnColumnSizes(int returnSize, int returnColumnSize) {
    if (returnSize == 0) {
        return NULL;
    }

    int i, *ret = (int *) malloc(sizeof(int) * returnSize);
    
    for (i = 0; i < returnSize; ++i) {
        ret[i] = returnColumnSize;
    }
    
    return ret;
}

int ** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (numsSize < 3) {
        return NULL;
    }
    
    qsort(nums, numsSize, sizeof(int), compare);
    
    int **ret = getRet(nums, numsSize, returnSize);

    *returnColumnSizes = getReturnColumnSizes(*returnSize, 3);
    return ret;
}
