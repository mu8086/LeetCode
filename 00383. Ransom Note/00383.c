#define ALPHABET_SIZE   26

bool canConstruct(char *ransomNote, char *magazine) {
    int i, len, freq[ALPHABET_SIZE] = {};
    
    for (i = 0, len = strlen(magazine); i < len; ++i) {
        ++freq[magazine[i] - 'a'];
    }
    
    for (i = 0, len = strlen(ransomNote); i < len; ++i) {
        --freq[ransomNote[i] - 'a'];
    }
    
    for (i = 0; i < ALPHABET_SIZE; ++i) {
        if (freq[i] < 0) {
            return false;
        }
    }
    
    return true;
}
