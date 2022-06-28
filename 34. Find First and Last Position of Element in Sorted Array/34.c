int findLesser(int *arr, int begin, int end, int target) {
    int ret = -1;
    int l = begin, r = end, half;
    
    while (true) {
        half = (l + r) / 2;
        
        if (arr[half] == target && (half == begin || arr[half-1] < target)) {
            ret = half;
            break;
        } else if (half == l) {
            if (arr[r] == target) {
                ret = r;
            }
            break;
        } else if (arr[half] >= target) {
            r = half-1;
        } else {
            l = half+1;
        }
    }
    
    return ret;
}

int findGreater(int *arr, int begin, int end, int target) {
    int ret = -1;
    int l = begin, r = end, half;
    
    while (true) {
        half = (l + r) / 2;
        
        if (arr[half] == target && (half == end || arr[half+1] > target)) {
            ret = half;
            break;
        } else if (half == l) {
            if (arr[r] == target) {
                ret = r;
            }
            break;
        } else if (arr[half] > target) {
            r = half-1;
        } else {
            l = half+1;
        }
    }
    
    return ret;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ret = (int *) malloc(sizeof(int) * 2);
    if (numsSize == 0) {
        ret[0] = ret[1] = -1;
        return ret;
    }
    
    ret[0] = findLesser(nums, 0, numsSize-1, target);
    ret[1] = (ret[0] == -1) ? -1 : findGreater(nums, 0, numsSize-1, target);
    
    *returnSize = 2;    
    return ret;
}
