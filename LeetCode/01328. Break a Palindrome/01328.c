char * breakPalindrome(char * palindrome) {
    int i, len = strlen(palindrome), mid = len / 2;

    if (len == 1) {
        return "";
    }

    for (i = 0; i < mid; ++i) {
        if (palindrome[i] != 'a') {
            palindrome[i] = 'a';
            return palindrome;
        }
    }

    palindrome[len-1] = 'b';

    return palindrome;
}
