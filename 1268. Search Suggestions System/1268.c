#define ALPHABET_SIZE   26
#define INVALID_INDEX   -1
#define SUGGEST_SIZE    3
#define MAX_NODE_SIZE   20000

typedef struct _Node {
    int index;
    struct _Node *next[ALPHABET_SIZE];
} Node;

Node * newNode(int mode) {
    static Node allocate[MAX_NODE_SIZE] = {};
    static Node *ret = allocate;
    
    if (mode == 0) { // first call newNode()
        memset(ret, 0, sizeof(Node) * MAX_NODE_SIZE);
        for (int i = 0; i < MAX_NODE_SIZE; ++i) {
            ret[i].index = INVALID_INDEX;
        }
    } else if (mode == 1) { // normal case
        ++ret;
    } else {    // do free
        ret = allocate;
    }
    
    return ret;
}

static inline int getIndex(char c) {
    return c - 'a';
}

void insertNode(Node *trie, char *s, int arrayIndex) {
    int index = getIndex(s[0]);
    
    if (trie->next[index] == NULL) {
        trie->next[index] = newNode(1);
    }
    
    if (s[1] != '\0') {
        insertNode(trie->next[index], s + 1, arrayIndex);
    } else {    // last character in string
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

bool isLastMatchUseable(char c, int index, char **s, int match[], int matchCount) {
    if (matchCount == 0) {
        return false;
    }
    
    for (int i = 0; i < matchCount; ++i) {
        if (index >= strlen(s[match[i]]) || c != s[match[i]][index]) {
            return false;
        }
    }

    return true;
}

void freeTrie(Node *trie) {
    newNode(-1);    // reset the static variable inside function
}

char *** suggestedProducts(char **products, int productsSize, char *searchWord, int *returnSize, int **returnColumnSizes) {
    int i, j, index, len_search = strlen(searchWord);
    int matchCount = 0, matchSize = sizeof(int) * SUGGEST_SIZE, match[SUGGEST_SIZE] = {};
    char ***ret = (char ***) malloc(sizeof(char **) * len_search);
    Node *trie = newNode(0), *walker;

    *returnSize = len_search;
    *returnColumnSizes = (int *) malloc(sizeof(int) * len_search);
    
    for (i = 0; i < productsSize; ++i) {
        insertNode(trie, products[i], i);
    }  
    
    for (i = 0, walker = trie; i < len_search; ++i) {
        if (walker != NULL) {
            index = getIndex(searchWord[i]);
            if (!isLastMatchUseable(searchWord[i], i, products, match, matchCount)) {
                matchCount = 0;
                memset(match, 0, matchSize);
                searchWords(walker->next[index], match, &matchCount);
            }
            
            if (matchCount > 0) {
                ret[i] = (char **) malloc(sizeof(char *) * matchCount);
                for (j = 0; j < matchCount; ++j) {
                    ret[i][j] = products[match[j]];
                }
            }

            walker = walker->next[index];
        } else {
            matchCount = 0;
        }

        (*returnColumnSizes)[i] = matchCount;
    }
    
    freeTrie(trie);
    return ret;
}
