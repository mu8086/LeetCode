bool isPowerOfThree(int n) {
    return n > 0 && n == pow(3, (int)(log10(n) / log10(3)));
}
