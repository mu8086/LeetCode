bool isPalindrome(char *s, int len_s) {
    for (int i=0, half=len_s/2, max_i=len_s-1; i<half; ++i) {
        if (s[i] != s[max_i-i]) {
            return false;
        }
    }
    return true;
}

int removePalindromeSub(char * s) {
    int len_s = strlen(s);
    
    if ( !isPalindrome(s, len_s) ) {
        while (--len_s > 0) {
            if ((s[len_s] + s[len_s-1]) % 2 == 1) {
                return 2;
            }
        }
    }
    
    return 1;
}
