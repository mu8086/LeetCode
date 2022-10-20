// https://leetcode.com/problems/integer-to-roman

char * intToRoman(int num) {
    int i;
    char s[20] = {}, *ans = NULL;

    i = 0;
    while (num >= 1000) {
        num -= 1000;
        s[i++] = 'M';
    }
    if (num >= 900) {
        num -= 900;
        s[i++] = 'C';
        s[i++] = 'M';
    } else if (num >= 500) {
        num -= 500;
        s[i++] = 'D';
    } else if (num >= 400) {
        num -= 400;
        s[i++] = 'C';
        s[i++] = 'D';
    }
    while (num >= 100) {
        num -= 100;
        s[i++] = 'C';
    }
    if (num >= 90) {
        num -= 90;
        s[i++] = 'X';
        s[i++] = 'C';
    } else if (num >= 50) {
        num -= 50;
        s[i++] = 'L';
    } else if (num >= 40) {
        num -= 40;
        s[i++] = 'X';
        s[i++] = 'L';
    }
    while (num >= 10) {
        num -= 10;
        s[i++] = 'X';
    }
    if (num >= 9) {
        num -= 9;
        s[i++] = 'I';
        s[i++] = 'X';
    } else if (num >= 5) {
        num -= 5;
        s[i++] = 'V';
    } else if (num >= 4) {
        num -= 4;
        s[i++] = 'I';
        s[i++] = 'V';
    }
    while (num >= 1) {
        num -= 1;
        s[i++] = 'I';
    }

    ans = (char *) malloc(sizeof(char) * (i+1));
    memcpy(ans, s, sizeof(char) * (i+1));
    return ans;
}
