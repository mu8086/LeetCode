int reverse(int x){
    int res=0;

    if (x != 0) {
        res = x % 10;
        x /= 10;
    }
    
    while (x != 0) {
        if (res >= 214748365 || res <= -214748365)
            return 0;

        res *= 10;
        res = res + x % 10;
        x /= 10;
    }
    
    return res;
}
