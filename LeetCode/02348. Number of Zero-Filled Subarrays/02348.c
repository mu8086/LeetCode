// https://leetcode.com/problems/number-of-zero-filled-subarrays

#define UNSET -1

long long subarraySize(long long size) {
    return (1+size) * size / 2;
}

long long zeroFilledSubarray(int *n, int nSize) {
    int l, i;
    long long ans = 0;

    for (i=0, l=UNSET; i<nSize; ++i) {
        if (n[i] == 0) {
            if (l == UNSET) {
                l = i;
            }
        } else if (l != UNSET) {
            ans += subarraySize(i-l);
            l = UNSET;
        }
    }
    if (l != UNSET) {
        ans += subarraySize(i-l);
    }

    return ans;
}
