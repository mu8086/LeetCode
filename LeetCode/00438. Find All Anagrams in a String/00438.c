#define ALPHABET_SIZE   26

void count(char *s, int size, int counter[]) {
    for (int i = 0; i < size; ++i) {
        ++counter[s[i] - 'a'];
    }
}

int * findAnagrams(char * s, char * p, int* returnSize) {
    *returnSize = 0;
    
    int lenS = strlen(s), lenP = strlen(p);
    if (lenS < lenP) {
        return NULL;
    }
    
    static int countSize = sizeof(int) * ALPHABET_SIZE;
    int counter[ALPHABET_SIZE] = {}, pCounter[ALPHABET_SIZE] = {};
    
    count(s, lenP, counter);
    count(p, lenP, pCounter);
    
    int *ret = (int *) malloc(sizeof(int) * (lenS-lenP+1));
    int left = 0, right = lenP;
    while (s[right] != '\0') {
        if (!memcmp(counter, pCounter, countSize)) {
            ret[(*returnSize)++] = left;
        }
        
        ++counter[s[right++] - 'a'];
        --counter[s[left++] - 'a'];
    }
    if (!memcmp(counter, pCounter, countSize)) {
        ret[(*returnSize)++] = left;
    }
    
    return ret;
}
