#define NEVER_SEEN  -100001

bool checkPossibility(int* nums, int numsSize) {
    if (numsSize <= 2) {
        return true;
    }
    
    int i, lastValid, last, flag, num;
    
    for (i = 1, lastValid = NEVER_SEEN, last = nums[0], flag = 0; i < numsSize; ++i) {
        num = nums[i];
        if (last != lastValid && last > num && lastValid > num) {
            return false;
        }
        
        if (last > num) {
            if (flag == 1) {
                return false;
            }
            flag = 1;
            
            lastValid = last;
            
            if (i >= 2 && nums[i-2] > num && i != numsSize-1 && nums[i+1] < last) {
                return false;
            }
        } else {
            lastValid = num;
        }
        last = num;
    }

    return true;
}
