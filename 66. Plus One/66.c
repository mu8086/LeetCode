int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* ret = NULL;
    
    digits[digitsSize-1]++;
    for (int i=digitsSize-1; i>0; i--) {
        if (digits[i] > 9) {
            digits[i] -= 10;
            digits[i-1]++;
        } else {
            break;
        }
    }
    
    if (digits[0] > 9) {
        *returnSize = digitsSize + 1;
        ret = (int*) malloc(sizeof(int) * *returnSize);
        digits[0] -= 10;
        ret[0] = 1;
        memcpy(&ret[1], digits, sizeof(int) * digitsSize);
    } else {
        *returnSize = digitsSize;
        ret = (int*) malloc(sizeof(int) * *returnSize);
        memcpy(ret, digits, sizeof(int) * digitsSize);
    }
    
    return ret;
}
