bool isPowerOfFour(int n) {
    if (n > 0) {
        while (n > 1 && n % 4 == 0) {
            n >>= 2;
        }
        
        return n == 1;
    }
    
    return false;
}
