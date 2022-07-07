bool isEvenDigits(int n) {
    int digits;
    
    for (digits=0; n > 0; n/=10) {
        digits++;
    }
    
    return digits % 2 == 0;
}

int findNumbers(int* nums, int numsSize){
    int count = 0;
    
    for (int i=0; i<numsSize; i++) {
        if (isEvenDigits(nums[i])) {
            count++;
        }
    }
    
    return count;
}
