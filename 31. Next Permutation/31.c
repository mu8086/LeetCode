void reverse(int* nums, int numsSize) {
    for (int i=0, half=numsSize/2, last=numsSize-1, tmp; i<half; i++) {
        tmp = nums[i];
        nums[i] = nums[last-i];
        nums[last-i] = tmp;
    }
}

void nextPermutation(int* nums, int numsSize){
    int dest, target, tmp;
    
    for (dest=numsSize-2; dest>=0; dest--) {
        if (nums[dest] < nums[dest+1]) {
            break;
        }
    }
    
    if (dest >= 0) {
        for (target=numsSize-1; target>dest; target--) {
            if (nums[dest] < nums[target]) {
                tmp = nums[target];
                nums[target] = nums[dest];
                nums[dest] = tmp;
                
                reverse(&nums[dest+1], numsSize-1-dest);
                return;
            }
        }
    }
    
    reverse(nums, numsSize);
    return;
}
