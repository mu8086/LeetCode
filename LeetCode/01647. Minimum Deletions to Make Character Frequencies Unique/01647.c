#define ALPHABET_SIZE 26

void setFeq(char *s, int feq[]) {
    char c;
    
    while ((c = *s) != '\0') {
        ++feq[c-'a'];
        ++s;
    }
}

int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int minDeletions(char * s) {
    int i, count, tmp;
    int feq[ALPHABET_SIZE] = {};
    
    setFeq(s, feq);
    qsort(feq, ALPHABET_SIZE, sizeof(int), compare);
    
    for (i = 1, count = 0; i < ALPHABET_SIZE && feq[i] > 0; ++i) {
        if (feq[i] >= feq[i-1]) {
            tmp = (feq[i-1] != 0) ? feq[i-1]-1 : 0;
            count += feq[i] - tmp;
            feq[i] = tmp;
        }
    }
    
    return count;
}
