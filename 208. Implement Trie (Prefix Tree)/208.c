#define ALPHABET_SIZE   26

typedef struct _Trie {
    bool            isLeaf;
    struct _Trie    *children[ALPHABET_SIZE];
} Trie;

Trie * newNode() {
    Trie *ret = (Trie *) malloc(sizeof(Trie));
    memset(ret, 0, sizeof(Trie));
    return ret;
}

Trie * trieCreate() {
    return newNode();
}

void trieInsert(Trie* obj, char * word) {
    int i;
    
    while ((i = *word - 'a') >= 0) {
        if (obj->children[i] == NULL) {
            obj->children[i] = newNode();
        }
        
        obj = obj->children[i];
        ++word;
    }
    obj->isLeaf = true;
}

bool trieSearch(Trie* obj, char * word) {
    int i;
    
    while ((i = *word - 'a') >= 0) {
        if (obj->children[i] == NULL) {
            return false;
        }
        
        obj = obj->children[i];
        ++word;
    }
    
    return obj->isLeaf;
}

bool trieStartsWith(Trie* obj, char * prefix) {
    int i;
    
    while ((i = *prefix - 'a') >= 0) {
        if (obj->children[i] == NULL) {
            return false;
        }
        
        obj = obj->children[i];
        ++prefix;
    }
    
    return true;
}

void trieFree(Trie* obj) {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (obj->children[i] != NULL) {
            trieFree(obj->children[i]);
        }
    }
    free(obj);
}
