int lengthOfLongestSubstring(char * s) {
    int begin, end, max, len;
    int lastIndex[CHAR_MAX] = {};

    for (begin = end = max = 0; s[end] != '\0'; ++end) {
        // found a new non-repeated character
        if (lastIndex[s[end]] >= begin) {
            len = end - begin;
            max = (len > max) ? len : max;
            begin = lastIndex[s[end]];
        }
        // indicate the new begin, if found this character later
        lastIndex[s[end]] = end+1;
    }
    len = end - begin;
    max = (len > max) ? len : max;

    return max;
}
