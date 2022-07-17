bool bs(int *nums, int beginIndex, int endIndex, int target) {
    int l = beginIndex, r = endIndex, half;
    
    while (true) {
        half = (l + r) / 2;
        
        if (nums[half] == target) {
            return true;
        } else if (half == l) {
            return nums[l] == target || nums[r] == target;
        } else if (nums[half] > target) {
            r = half-1;
        } else if (nums[half] < target) {
            l = half+1;
        }
    }
    
    return false;
}

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target) {
    int numsSize = matrixSize * *matrixColSize;
    int *nums = (int *) malloc(sizeof(int) * numsSize);
    
    for (int i = numsSize - 1, col = *matrixColSize; i >= 0; --i) {
        nums[i] = matrix[i / col][i % col];
    }
    
    bool res = bs(nums, 0, numsSize - 1, target);
    
    free(nums);
    return res;
}
