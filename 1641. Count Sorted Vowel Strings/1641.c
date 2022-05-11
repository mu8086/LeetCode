int countVowelStrings(int n);

int sum1toN(int n) {
    static int sum[51] = {};
    
    if (n != 0 && sum[n] == 0) {
        sum[n] = sum1toN(n-1) + n;
    }
    return sum[n];
} 

int a(int n) {
    return countVowelStrings(n-1);
}

int e(int n) {
    return countVowelStrings(n-1) - countVowelStrings(n-2);
}

int i(int n) {
    return sum1toN(n);
}

int o(int n) {
    return n;
}

int u(int n) {
    return 1;
}

int countVowelStrings(int n){
    static int count[51] = {1, 5};
    
    if (count[n] == 0) {
        count[n] = a(n)+e(n)+i(n)+o(n)+u(n);
    }
    return count[n];
}
