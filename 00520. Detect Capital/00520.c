// https://leetcode.com/problems/detect-capital

bool isUpper(int c) {
    return 'A' <= c && c <= 'Z';
}

bool detectCapitalUse(char *word) {
    int len = strlen(word);
    
    if (len == 1) {
        return true;
    }

    bool first = isUpper(word[0]);
    bool second = isUpper(word[1]);

    if (!first && second) {
        return false;
    }

    for (int i = 2; i < len; ++i) {
        if (isUpper(word[i]) != second) {
            return false;
        }
    }

    return true;
}
