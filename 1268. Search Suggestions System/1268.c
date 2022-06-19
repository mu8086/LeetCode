#define ALPHABET_SIZE   26
#define INVALID_INDEX   -1
#define SUGGEST_SIZE    3

typedef struct _Node {
    int index;
    struct _Node *next[ALPHABET_SIZE];
} Node;

Node * newNode(void) {
    Node *ret = (Node *) malloc(sizeof(Node));
    memset(ret, 0, sizeof (Node));
    ret->index = INVALID_INDEX;
    
    return ret;
}

static inline int getIndex(char c) {
    return c - 'a';
}

void insertNode(Node *trie, char *s, int arrayIndex) {
    int index = getIndex(s[0]);
    
    if (trie->next[index] == NULL) {
        trie->next[index] = newNode();
    }
    
    if (s[1] != '\0') {
        insertNode(trie->next[index], s + 1, arrayIndex);
    } else {
        trie->next[index]->index = arrayIndex;
    }
}

void searchWords(Node *trie, int match[], int *matchCount) {
    if (trie != NULL) {
        if (trie->index != INVALID_INDEX) {
            match[(*matchCount)++] = trie->index;
        }
        
        for (int i = 0; i < ALPHABET_SIZE && *matchCount < SUGGEST_SIZE; ++i) {
            if (trie->next[i] != NULL) {
                searchWords(trie->next[i], match, matchCount);
            }
        }
    }
}

void freeTrie(Node *trie) {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (trie->next[i] != NULL) {
            freeTrie(trie->next[i]);
        }
    }
    free(trie);
}

char *** suggestedProducts(char **products, int productsSize, char *searchWord, int *returnSize, int **returnColumnSizes) {
    int i, j, index, len_search = strlen(searchWord), matchCount = 0;
    char ***ret = (char ***) malloc(sizeof(char **) * len_search);
    Node *trie = newNode(), *walker;

    *returnSize = len_search;
    *returnColumnSizes = (int *) malloc(sizeof(int) * len_search);
    
    for (i = 0; i < productsSize; ++i) {
        insertNode(trie, products[i], i);
    }  
    
    for (i = 0, walker = trie; i < len_search; ++i) {
        matchCount = 0;

        if (walker != NULL) {
            int match[SUGGEST_SIZE] = {};
            
            index = getIndex(searchWord[i]);
            
            searchWords(walker->next[index], match, &matchCount);
            
            if (matchCount > 0) {
                ret[i] = (char **) malloc(sizeof(char *) * matchCount);
                for (j = 0; j < matchCount; ++j) {
                    ret[i][j] = products[match[j]];
                }
            }

            walker = walker->next[index];
        }
        
        (*returnColumnSizes)[i] = matchCount;
    }
    
    freeTrie(trie);
    return ret;
}
