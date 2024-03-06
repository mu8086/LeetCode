int removeDuplicates(int* nums, int numsSize){
    int i, newSize;
    
    for (i=1, newSize=0; i<numsSize; ++i) {
        if (nums[i] > nums[newSize]) {
            ++newSize;
            nums[newSize] = nums[i];
        }
    }
    
    return newSize + 1;
}
