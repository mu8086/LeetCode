#define DIGIT_SIZE  10

char * largestPalindromic(char *num) {
    int i, len, numI, leading, pair;
    int freq[DIGIT_SIZE] = {};

    for (i = 0, len = strlen(num); i < len; ++i) {
        ++freq[num[i] - '0'];
    }
    
    numI = 0;
    leading = 0;
    // set leading digit
    for (i = DIGIT_SIZE-1; i >= 1; --i) {
        if (freq[i] >= 1) {
            leading = (leading > i) ? leading : i;
            
            if (freq[i] >= 2) {
                freq[i] -= 2;
                leading = i;
                num[numI++] = i + '0';
                break;
            }
        }
    }
    if (i == 0) {
        num[0] = leading + '0';
        num[1] = '\0';
        return num;
    }
    
    // count pair
    for (i = DIGIT_SIZE-1; i >= 0; --i) {
        while (freq[i] >= 2) {
            freq[i] -= 2;
            num[numI++] = i + '0';
        }
    }
    pair = numI;
    
    // center digit
    for (i = DIGIT_SIZE-1; i >= 0; --i) {
        if (freq[i] != 0) {
            num[numI++] = i + '0';
            break;
        }
    }
    
    // reflect from the center
    for (i = pair-1; i >= 0; --i) {
        num[numI++] = num[i];
    }
    num[numI] = '\0';
    
    return num;
}
