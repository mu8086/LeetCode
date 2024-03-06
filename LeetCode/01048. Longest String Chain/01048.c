#define NOT_FOUND -1

bool isPredecessor(char *word1, char *word2, int len_1, int len_2) {
    int i, j, diff;
    
    if (len_1 + 1 != len_2) {
        return false;
    }
    
    for (i = 0, j = 0, diff = 0; i < len_1 && j < len_2; ++i, ++j) {
        if (word1[i] != word2[j]) {
            if (diff == 1) {
                return false;
            }
            diff = 1;
            --i;
        }
    }
    
    return true;
}

int * getLens(char **words, int wordsSize) {
    int i, *ret = (int *) malloc(sizeof(int) * wordsSize);
    
    for (i = 0; i < wordsSize; ++i) {
        ret[i] = strlen(words[i]);
    }
    
    return ret;
}

int * getCounter(int wordsSize) {
    int *ret = (int *) malloc(sizeof(int) * wordsSize);
    memset(ret, 0, sizeof(int) * wordsSize);
    return ret;
}

int getTargetValueIndex(int *lens, int lensSize, int targetValue, int start_index) {
    for (int i = start_index; i < lensSize; ++i) {
        if (lens[i] == targetValue) {
            return i;
        }
    }
    
    return NOT_FOUND;
}

int compare(const void *a, const void *b) {
    int len_a = strlen(*(char**)a);
    int len_b = strlen(*(char**)b);
    return len_a - len_b;
}

int longestStrChain(char ** words, int wordsSize) {
    qsort(words, wordsSize, sizeof(char *), compare);

    int *lens = getLens(words, wordsSize);
    int *counter = getCounter(wordsSize);
    
    int i, j, ret = 0;
    int shorter_index = 0, longer_index, longer_size = lens[0] + 1;
    
    while ((longer_index = getTargetValueIndex(lens, wordsSize, longer_size, shorter_index+1)) != NOT_FOUND) {
        for (i = shorter_index; i < longer_index; ++i) {
            for (j = longer_index; j < wordsSize && lens[j] == longer_size; ++j) {
                if (counter[i] + 1 > counter[j] && isPredecessor(words[i], words[j], lens[i], lens[j])) {
                    counter[j] = counter[i] + 1;
                    ret = (counter[j] > ret) ? counter[j] : ret;
                }
            }
        }
        
        shorter_index = longer_index;
        longer_size = lens[longer_index] + 1;
    }

    free(lens);
    free(counter);
    return ret + 1;
}
