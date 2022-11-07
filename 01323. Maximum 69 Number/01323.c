// https://leetcode.com/problems/maximum-69-number

int maximum69Number (int num) {
    int i, i6, ans = num;

    for (i = 0, i6 = -1; num > 0; ++i, num /= 10) {
        if (num % 10 == 6) {
            i6 = i;
        }
    }
    if (i6 != -1) {
        num = 3;
        while (i6--) {
            num *= 10;
        }
    }

    return ans + num;
}
