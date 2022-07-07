#define ALPHABET_SIZE       27
#define INVALID             -1
#define DELIMITER           '{'
#define MAX_LONG_WORD_SIZE  22 // word + '{' + word + '\0'

typedef struct _trie {
    //int index;
    int childMaxIndex;
    struct _trie *children[ALPHABET_SIZE];
} Trie;

typedef struct {
    Trie *trie;
} WordFilter;

Trie *newTrieNode() {
    static int trieSize = sizeof(Trie);
    Trie *trie = (Trie *) malloc(trieSize);
    memset(trie, 0, trieSize);
    
    return trie;
}

void trieInsert(Trie *trie, char *s, int wordsIndex) {
    char charIndex;
    
    while ((charIndex = *s - 'a') >= 0) {
        trie->childMaxIndex = wordsIndex;
        
        if (trie->children[charIndex] == NULL) {
            trie->children[charIndex] = newTrieNode();
        }

        trie = trie->children[charIndex];
        ++s;
    }
    trie->childMaxIndex = wordsIndex;
    //trie->index = wordsIndex;
}

int trieSearch(Trie *trie, char *s) {
    char charIndex;
    
    while ((charIndex = *s - 'a') >= 0) {
        if (trie->children[charIndex] == NULL) {
            return INVALID;
        }
        
        trie = trie->children[charIndex];
        ++s;
    }
    
    return trie->childMaxIndex;
}

void trieFree(Trie *trie) {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (trie->children[i] != NULL) {
            trieFree(trie->children[i]);
        }
    }
    free(trie);
}

WordFilter* wordFilterCreate(char ** words, int wordsSize) {
    Trie *trie = newTrieNode();
    WordFilter *ret = (WordFilter *) malloc(sizeof(WordFilter));
    ret->trie = trie;
    
    int lenWord, i;
    char *walker, longWord[MAX_LONG_WORD_SIZE] = {};
    
    for (i = 0; i < wordsSize; ++i) {
        lenWord = strlen(words[i]);
        memcpy(longWord, words[i], lenWord);
        longWord[lenWord] = DELIMITER;
        memcpy(&longWord[lenWord+1], words[i], lenWord+1);
        
        for (walker = longWord; *walker != DELIMITER; ++walker) {
            trieInsert(trie, walker, i);
        }
    }
    
    return ret;
}

int wordFilterF(WordFilter* obj, char * prefix, char * suffix) {
    char target[MAX_LONG_WORD_SIZE] = {};
    int lenSuffix = strlen(suffix);
    
    memcpy(target, suffix, lenSuffix);
    target[lenSuffix] = DELIMITER;
    memcpy(&target[lenSuffix+1], prefix, strlen(prefix)+1);
    
    return trieSearch(obj->trie, target);
}

void wordFilterFree(WordFilter* obj) {
    trieFree(obj->trie);
    free(obj);
}
