#define RED     0
#define WHITE   1
#define BLUE    2

void sortColors(int* nums, int numsSize){
    int i, redCount = 0, whiteCount = 0, blueCount = 0;
    
    for (i=0; i<numsSize; ++i) {
        if (nums[i] == 0) {
            ++redCount;
        } else if (nums[i] == 1) {
            ++whiteCount;
        }
    }
    
    memset(nums, 0, sizeof(int) * redCount);

    i = redCount - 1;
    while (--whiteCount >= 0) {
        nums[++i] = WHITE;
    }
    
    blueCount = numsSize - i - 1;
    while (--blueCount >= 0) {
        nums[++i] = BLUE;
    }
}
