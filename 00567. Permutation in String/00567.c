#define ALPHABET_SIZE   26

void count(char *s, int size, int counter[]) {
    for (int i = 0; i < size; ++i) {
        ++counter[s[i] - 'a'];
    }
}

bool findAnagrams(char * p, char * s) {
    int lenS = strlen(s), lenP = strlen(p);
    if (lenS < lenP) {
        return false;
    }
    
    static int countSize = sizeof(int) * ALPHABET_SIZE;
    int counter[ALPHABET_SIZE] = {}, pCounter[ALPHABET_SIZE] = {};
    
    count(s, lenP, counter);
    count(p, lenP, pCounter);
    
    int left = 0, right = lenP;
    while (s[right] != '\0') {
        if (!memcmp(counter, pCounter, countSize)) {
            return true;
        }
        
        ++counter[s[right++] - 'a'];
        --counter[s[left++] - 'a'];
    }
    if (!memcmp(counter, pCounter, countSize)) {
        return true;
    }
    
    return false;
}

bool checkInclusion(char * s1, char * s2){
    return findAnagrams(s1, s2);
}
