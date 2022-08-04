int getGcd(int a, int b) {
    if (b != 0) {
        while ((a %= b) && (b %= a)) ;
    }
    return a + b;
}

int getLcm(int a, int b) {
    return a * b / getGcd(a, b);
}

int mirrorReflection(int p, int q) {
    int lcm = getLcm(p, q);
    
    if ((lcm / q) & 1) {
        return (lcm / p) & 1 ? 1 : 0;
    }
    
    return 2;
}
