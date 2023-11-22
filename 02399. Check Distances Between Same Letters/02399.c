// https://leetcode.com/problems/check-distances-between-same-letters

bool checkDistances(char * s, int *d, int distSize) {
    int i, j, dist, len;

    for (i = 0, len = strlen(s); i < len; ++i) {
        dist = d[s[i]-'a'];

        if ((i - dist - 1 >= 0 && s[i - dist - 1] == s[i]) || (i + dist + 1 < len && s[i + dist + 1] == s[i])) {
            ;
        } else {
            return false;
        }
    }

    return true;
}
