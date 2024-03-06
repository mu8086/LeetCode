// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

#define MAXSIZE 1001

bool arrayStringsAreEqual(char ** word1, int word1Size, char ** word2, int word2Size){
    char s1[MAXSIZE] = {}, s2[MAXSIZE] = {};
    int word, len, idx;

    for (word = 0, idx = 0; word < word1Size; ++word) {
        len = strlen(word1[word]);
        memcpy(s1 + idx, word1[word], len);
        idx += len;
    }

    for (word = 0, idx = 0; word < word2Size; ++word) {
        len = strlen(word2[word]);
        memcpy(s2 + idx, word2[word], len);
        idx += len;
    }

    return !memcmp(s1, s2, MAXSIZE);
}
