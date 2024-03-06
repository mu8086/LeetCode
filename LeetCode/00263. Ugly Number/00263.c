// https://leetcode.com/problems/ugly-number/description/

bool isUgly(int n) {
    if (n < 1) {
        return false;
    }

    while ((n & 1) == 0) {
        n >>= 1;
    }

    while (n % 3 == 0) {
        n /= 3;
    }

    while (n % 5 == 0) {
        n /= 5;
    }

    return n == 1;
}
