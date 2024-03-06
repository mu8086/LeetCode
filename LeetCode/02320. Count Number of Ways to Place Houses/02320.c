#define MAX_N   10002
#define MOD_VAL 1000000007

long long getFib(int n) {
    static long long fib[MAX_N] = {1, 1};
    
    if (fib[n] == 0) {
        fib[n] = (getFib(n-1) % MOD_VAL + getFib(n-2) % MOD_VAL) % MOD_VAL;
    }
    
    return fib[n];
}

long long square(long long n) {
    return n * n % MOD_VAL;
}

int countHousePlacements(int n){
    return square(getFib(n+1));
}
