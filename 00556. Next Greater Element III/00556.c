int compare(const void* a, const void* b) {
    return *((const int*) a) > *((const int*) b);
}

void sort(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void nextPermutation(int* nums, int numsSize){  
    for (int i, j=numsSize-2; j>=0; j--) {
        for (i=numsSize-1; i>j; i--) {
            if (nums[i] > nums[j]) {
                swap(&nums[i], &nums[j]);
                sort(&nums[j+1], numsSize-j-1);
                return;
            }
        }
    }

    sort(nums, numsSize);
    return;
}

int* initNums(int n, int* numsSize) {
    int* nums = (int*) malloc(sizeof(int) * 10);
    memset(nums, 0, sizeof(int) * 10);
    
    for (*numsSize=0; n>0; n/=10) {
        nums[(*numsSize)++] = n%10;
    }
    
    return nums;
}

void reverse(int* nums, int numsSize) {
    for (int i=numsSize/2-1, tmp; i>=0; i--) {
        tmp = nums[i];
        nums[i] = nums[numsSize-1-i];
        nums[numsSize-1-i] = tmp;
    }
}

int intArrayToInt(int* nums, int numsSize) {
    int ret = 0, last_digit = numsSize-1;
    
    for (int i=0; i<last_digit; i++, ret*=10) {
        ret += nums[i];
        if (ret > 214748364) {
            return 0;
        }
    }
    if (ret == 2147483640 && nums[last_digit] > 7) {
        ret = 0;
    } else {
        ret += nums[last_digit];
    }
    
    return ret;
}

int nextGreaterElement(int n){
    int numsSize=0;
    int* nums = initNums(n, &numsSize);
    
    reverse(nums, numsSize);
    
    nextPermutation(nums, numsSize);
    
    int tmp = intArrayToInt(nums, numsSize);
    int ret = (tmp > n) ? tmp : -1;

    return ret;
}
