int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    *returnSize = 2;
    int *ret = (int *) malloc(sizeof(int) * 2);
    
    int i = 0, j = numbersSize-1, diff;
    
    while (i < j) {
        diff = target - numbers[i];
    
        if (diff == numbers[j]) {
            ret[0] = i+1;
            ret[1] = j+1;
            break;
        } else if (diff > numbers[j]) {
            ++i;
        } else {
            --j;
        }
    }
    
    return ret;
}
