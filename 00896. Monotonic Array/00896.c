bool isMonotonic(int* nums, int numsSize){
    bool increasing = false, decreasing = false;
    int numsSize_1 = numsSize-1;
    
    for (int i=0; i<numsSize_1; i++) {
        if (nums[i] < nums[i+1]) {
            increasing = true;
        }
        if (nums[i] > nums[i+1]) {
            decreasing = true;
        }
        if (increasing && decreasing) {
            return false;
        }
    }
    
    return true;
}
