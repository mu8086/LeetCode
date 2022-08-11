#define ALPHABET_SIZE   26

void setFeq(int result[], char **words2, int words2Size) {
    char c;
    
    for (int i = 0, j, index; i < words2Size; ++i) {
        int feq[ALPHABET_SIZE] = {};
        
        for (j = 0, c = words2[i][j]; c != '\0'; ++j, c = words2[i][j]) {
            index = c - 'a';
            
            if (++feq[index] > result[index]) {
                ++result[index];
            }
        }
    }
}

void setSingleWordFeq(int feq[], char *word) {
    for (int i = 0; word[i] != '\0'; ++i) {
        ++feq[word[i]-'a'];
    }
}

bool isSubsetFeq(int feq[], int singleWordFeq[]) {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (feq[i] > singleWordFeq[i]) {
            return false;
        }
    }
    
    return true;
}

char ** wordSubsets(char **words1, int words1Size, char **words2, int words2Size, int *returnSize) {
    *returnSize = 0;
    char **ret = (char **) malloc(sizeof(char *) * words1Size);
    
    char c;
    int i, j, feq[ALPHABET_SIZE] = {};
    
    setFeq(feq, words2, words2Size);
    
    for (i = 0; i < words1Size; ++i) {
        int singleWordFeq[ALPHABET_SIZE] = {};
        
        setSingleWordFeq(singleWordFeq, words1[i]);
        
        if (isSubsetFeq(feq, singleWordFeq)) {
            ret[(*returnSize)++] = words1[i];
        }
    }

    return ret;
}
