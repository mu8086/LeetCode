int removeElement(int* nums, int numsSize, int val) {
    int i, newSize;
    
    for (i=0, newSize=0; i<numsSize; ++i) {
        if (nums[i] != val) {
            nums[newSize] = nums[i];
            ++newSize;
        }
    }
    
    return newSize;
}
