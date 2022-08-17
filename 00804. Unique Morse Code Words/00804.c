#define ALPHABET_SIZE   26

void doFree(char **codes, int size) {
    while (--size >= 0) {
        if (codes[size] != NULL) {
            free(codes[size]);
        }
    }
    free(codes);
}

char * getCode(char *word) {
    static char *table[ALPHABET_SIZE] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    char *code = (char *) malloc(sizeof(char) * (4 * strlen(word) + 1));
    
    int i, j, codeIndex, tableIndex;
    
    for (i = 0, codeIndex = 0; word[i] != '\0'; ++i) {
        tableIndex = word[i] - 'a';
        for (j = 0; table[tableIndex][j] != '\0'; ++j) {
            code[codeIndex++] = table[tableIndex][j];
        }
    }
    code[codeIndex] = '\0';
    
    return code;
}

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int uniqueMorseRepresentations(char **words, int wordsSize) {
    int i, count, len_1, len_2;
    char **codes = (char **) malloc(sizeof(char *) * wordsSize);
    memset(codes, 0, sizeof(char *) * wordsSize);
    
    for (i = 0; i < wordsSize; ++i) {
        codes[i] = getCode(words[i]);
    }
    
    qsort(codes, wordsSize, sizeof(char *), compare);
    
    for (i = 1, count = 1; i < wordsSize; ++i) {
        len_1 = strlen(codes[i-1]);
        len_2 = strlen(codes[i]);
        len_1 = (len_1 < len_2) ? len_1 : len_2;
        
        if (memcmp(codes[i-1], codes[i], len_1 + 1)) {
            ++count;
        }
    }
    
    doFree(codes, wordsSize);
    return count;
}
