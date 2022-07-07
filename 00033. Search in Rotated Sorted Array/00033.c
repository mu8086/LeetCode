int _search(int *nums, int numsSize, int target, int begin, int end) {
    int half = (begin + end) / 2;
    
    if (nums[half] == target) {
        return half;
    } else if (begin == end) {
        return -1;
    } else if (nums[half] > target) {
        if (nums[begin] > nums[half] || nums[begin] <= target) {
            // find left
            return _search(nums, numsSize, target, begin, half);
        } else {
            // find right
            return _search(nums, numsSize, target, half+1, end);
        }
    } else {    // nums[half] < target
        if (nums[half] > nums[end] || nums[end] >= target) {
            // find right
            return _search(nums, numsSize, target, half+1, end);
        } else {
            // find left
            return _search(nums, numsSize, target, begin, half);
        }
    }
}

int search(int* nums, int numsSize, int target) {
    return _search(nums, numsSize, target, 0, numsSize-1);
}
