int maximumXOR(int* nums, int numsSize){
    int usedBits;
    
    for (--numsSize, usedBits = 0; numsSize >= 0 ; --numsSize) {
        usedBits |= nums[numsSize];
    }
    
    return usedBits;
}
