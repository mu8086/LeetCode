int wiggleMaxLength(int* nums, int numsSize) {
    int i, max;
    bool flag;

    for (i = 1, max = 0; i < numsSize; ++i) {
        if (nums[i-1] != nums[i]) {
            if (max == 0) {
                flag = nums[i-1] > nums[i];
                ++max;
            } else if (flag != nums[i-1] > nums[i]) {
                flag = nums[i-1] > nums[i];
                ++max;
            }
        }
    }
    
    return max + 1;
}
