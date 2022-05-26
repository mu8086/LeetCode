#define INVALID     -1
#define INIT_VAL    100001

int minOperations(int* nums, int numsSize, int x) {
    int ret = INIT_VAL;
    int sum, other_sum;
    int left, right, count, tmp;
    
    for (tmp = 0, sum = 0; tmp < numsSize; tmp++) {
        sum += nums[tmp];
    }
    if (sum < x) {
        return INVALID;
    } else if (sum == x) {
        return numsSize;
    }

    // sum = x + other_sum
    // use other_sum to find out longest subarray
    // minimum operations = numsSize - length of longest subarray
    other_sum = sum - x;
    
    left = right = count = 0;
    while (right < numsSize) {
        count += nums[right++];
        
        while (count > other_sum) {
            count -= nums[left++];;
        }
        
        if (count == other_sum) {
            tmp = numsSize-(right-left);
            ret = (tmp < ret) ? tmp : ret;
        }
    }

    return ret != INIT_VAL ? ret : INVALID;
}
