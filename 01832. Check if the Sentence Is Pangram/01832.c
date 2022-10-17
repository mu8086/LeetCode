// https://leetcode.com/problems/check-if-the-sentence-is-pangram

#define ALPHABET_SIZE   26

bool checkIfPangram(char * sentence) {
    bool exists[ALPHABET_SIZE] = {};
    int i;

    for (i = strlen(sentence)-1; i >= 0; --i) {
        exists[sentence[i] - 'a'] = true;
    }

    for (i = 0; i < ALPHABET_SIZE; ++i) {
        if (exists[i] == false) {
            return false;
        }
    }

    return true;
}
