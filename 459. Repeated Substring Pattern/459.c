bool repeatedSubstringPattern(char * s){
    int len_s = strlen(s);
    
    for (int i=1, maxSubStrSize=len_s/2, flag; i<=maxSubStrSize; i++) {
        flag = 0;
        if (len_s % i != 0) {
            continue;
        }
        
        for (int j=0; j<i; j++) {   // traverse first substr
            for (int k=j+i; k<len_s; k+=i) {    // jump to all other substr
                if (s[j] != s[k]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                break;
            }
        }
        if (flag == 0) {
            return true;
        }
    }
    
    return false;
}
