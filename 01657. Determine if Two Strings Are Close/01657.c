// https://leetcode.com/problems/determine-if-two-strings-are-close

#define ALPHABET_SIZE 26

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int * getFreq(char *s, int len) {
    int i, freqSize = sizeof(int) * ALPHABET_SIZE;
    int *freq = (int *) malloc(freqSize);
    memset(freq, 0, freqSize);
    
    for (i=0; i<len; ++i) {
        freq[s[i] - 'a']++;
    }

    return freq;
}

bool matchFreqMap(int *freq1, int *freq2, int size) {
    bool map1[ALPHABET_SIZE] = {};
    bool map2[ALPHABET_SIZE] = {};

    for (int i=0; i<size; ++i) {
        if (freq1[i] != 0)
            map1[i] = true;
        if (freq2[i] != 0)
            map2[i] = true;
    }

    return !memcmp(map1, map2, sizeof(bool) * ALPHABET_SIZE);
}

bool closeStrings(char * word1, char * word2){
    int len1 = strlen(word1), len2 = strlen(word2);
    if (len1 != len2)
        return false;

    int *freq1 = getFreq(word1, len1);
    int *freq2 = getFreq(word2, len2);

    if (!matchFreqMap(freq1, freq2, ALPHABET_SIZE)) {
        return false;
    }

    qsort(freq1, ALPHABET_SIZE, sizeof(int), compare);
    qsort(freq2, ALPHABET_SIZE, sizeof(int), compare);

    return !memcmp(freq1, freq2, sizeof(int) * ALPHABET_SIZE);
}
