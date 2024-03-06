#define ALPHABET_SIZE   26

void countFeq(char *s, int feq[], int increment) {
    char c;
    
    while ((c = *s) != '\0') {
        feq[c-'a'] += increment;
        ++s;
    }
}

bool verifyFeq(int feq[]) {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (feq[i] != 0) {
            return false;
        }
    }
    
    return true;
}

bool isAnagram(char * s, char * t) {
    static int feq[ALPHABET_SIZE], feqSize = sizeof(int) * ALPHABET_SIZE;
    memset(feq, 0, feqSize);
    
    countFeq(s, feq, 1);
    countFeq(t, feq, -1);
    
    return verifyFeq(feq);
}
