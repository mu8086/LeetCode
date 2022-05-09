char * getLetters(char digit) {
    switch (digit) {
        case '2':   return "abc";
        case '3':   return "def";
        case '4':   return "ghi";
        case '5':   return "jkl";
        case '6':   return "mno";
        case '7':   return "pqrs";
        case '8':   return "tuv";
        case '9':   return "wxyz";
        default:    return NULL;
    }
}

void func(char buf[], char * digits, int index_d, char ** ret, int* returnSize) {
    int len_d = strlen(digits);
    if (len_d == 0) {
        return;
    }
    
    char* letters = getLetters(digits[index_d]);
    
    for (int i=0, len_l = strlen(letters); i<len_l; i++) {
        buf[index_d] = letters[i];
        
        if (len_d == index_d+1) { // last digit
            ret[*returnSize] = malloc(strlen(buf) + 1);
            memcpy(ret[*returnSize], buf, strlen(buf) + 1);
            (*returnSize)++;
        } else {
            func(buf, digits, index_d+1, ret, returnSize);
        }
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    char ** ret = malloc(sizeof(char*) * 256);
    char buf[5] = {};
    
    *returnSize = 0;
    func(buf, digits, 0, ret, returnSize);
    
    return ret;
}
