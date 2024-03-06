bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

char * reverseVowels(char *s) {
    char tmp;
    int left, right = strlen(s)-1;
    bool isLeft = false, isRight = false;

    while (left < right) {
        isLeft  = isVowel(s[left]);
        isRight = isVowel(s[right]);

        if (isLeft && isRight) {
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
        } else if (isLeft) {
            --left;
        } else if (isRight) {
            ++right;
        }
        ++left;
        --right;
    }

    return s;
}
