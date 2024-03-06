#define MAX_SIZE        50
#define ALPHABET_SIZE   26

bool isValid(char *word, char *pattern) {
    int indexA, indexB;
    char pattern_to_word[ALPHABET_SIZE] = {}, word_to_pattern[ALPHABET_SIZE] = {};
    
    while (*pattern != '\0') {
        indexA = *pattern - 'a';
        indexB = *word    - 'a';
        
        if (pattern_to_word[indexA] == 0) {
            if (word_to_pattern[indexB] == 0) {
                pattern_to_word[indexA] = *word;
                word_to_pattern[indexB] = *pattern;
            } else {
                return false;
            }
        } else if (pattern_to_word[indexA] != *word) {
            return false;
        }
        
        ++pattern, ++word;
    }
    
    return true;
}

char ** findAndReplacePattern(char **words, int wordsSize, char *pattern, int *returnSize) {
    int i;
    char **ret = (char **) malloc(sizeof(char *) * MAX_SIZE);
    memset(ret, 0, sizeof(char *) * MAX_SIZE);
    
    for (i = 0, *returnSize = 0; i < wordsSize; ++i) {
        if (isValid(words[i], pattern)) {
            ret[(*returnSize)++] = words[i];
        }
    }
    
    return ret;
}
