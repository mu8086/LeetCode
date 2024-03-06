int transform(int n) {
    int i, freq[10] = {};
    
    // classify by digit
    for (i = 0; n > 0; ++i, n /= 10) {
        ++freq[n % 10];
    }

    // set leading digit
    for (i = 1; i < 10; ++i) {
        if (freq[i] > 0) {
            --freq[i];
            n += i;
            break;
        }
    }
    
    for (i = 0; i < 10; ++i) {
        while (freq[i] > 0) {
            --freq[i];
            n *= 10;
            n += i;
        }
    }
    
    return n;
}

bool found(int pow2[], int n) {
    for (int i = 0; i < 30; ++i) {
        if (n == pow2[i]) {
            return true;
        }
    }
    
    return false;
}

bool reorderedPowerOf2(int n) {
    static int once = false, pow2[30] = {};
    
    if (once == false) {
        once = true;
        
        for (int i = 0, tmp = 1; i < 30; ++i, tmp *= 2) {
            pow2[i] = transform(tmp);
        }
    }
    
    return found(pow2, transform(n));
}
