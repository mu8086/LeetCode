 int hammingWeight(uint32_t n) {
    int count;
    
    for (count=0; n > 0; n>>=1) {
        if (n & 1 == 1) {
            count++;
        }
    }
    
    return count;
}
