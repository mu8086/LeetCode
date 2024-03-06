char * shiftingLetters(char *s, int **shifts, int shiftsSize, int *shiftsColSize) {
    int i, len = strlen(s), sum;
    int totalShifts[50001] = {};
    
    for (i = 0; i < shiftsSize; ++i) {
        totalShifts[shifts[i][0]]   += (shifts[i][2] == 1) ? 1 : -1;
        totalShifts[shifts[i][1]+1] -= (shifts[i][2] == 1) ? 1 : -1;
    }
    
    for (i = 0, sum = 0; i < len; ++i) {
        sum += totalShifts[i];
        s[i] = (((s[i] - 'a') + sum) % 26 + 26) % 26 + 'a';
    }

    return s;
}
