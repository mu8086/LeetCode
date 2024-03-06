int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int bagOfTokensScore(int* tokens, int tokensSize, int power) {
    if (tokensSize == 0) {
        return 0;
    }

    qsort(tokens, tokensSize, sizeof(int), compare);

    int max = 0, score = 0, l = 0, r = tokensSize-1;

    while (l <= r) {
        if (power >= tokens[l]) {
            power -= tokens[l++];
            ++score;
            max = (max > score) ? max : score;
        } else if (score > 0) {
            power += tokens[r--];
            --score;
        } else {
            break;
        }
    }

    return max;
}
