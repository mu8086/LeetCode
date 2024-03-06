// https://leetcode.com/problems/count-and-say

char * getAns(char *s, char t[]) {
    char *ans = NULL, c;
    int count, reverse_count;
    int sIdx = 0, tIdx = 0, len = strlen(s);
    
    while (sIdx < len) {
        c = s[sIdx++];

        // count freq
        for (count = 1; c == s[sIdx]; ++sIdx) {
            ++count;
        }

        // reverse count digits, fill to reverse_count
        reverse_count = 0;
        while (count != 0) {
            reverse_count *= 10;
            reverse_count += count % 10;
            count /= 10;
        }

        // reverse count, fill to t[]
        while (reverse_count != 0) {
            t[tIdx++] = (reverse_count % 10) + '0';
            reverse_count /= 10;
        }

        // fill the character c to t[]
        t[tIdx++] = c;
    }
    t[tIdx] = '\0';

    len = strlen(t) + 1;
    ans = (char *) malloc(sizeof(char) * len);
    memcpy(ans, t, len);

    return ans;
}

char * countAndSay(int n) {
    static bool once = false;
    static char *ans[30] = {"1"};

    if (!once) {
        once = true;

        // hack the answer
        char tmp[4463] = {};

        for (int i = 1; i < 30; ++i) {
            ans[i] = getAns(ans[i-1], tmp);
        }
    }

    return ans[n-1];
}
