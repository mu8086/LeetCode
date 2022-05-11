int fib(int n){
    static int ret[31] = {0, 1};
    
    if (n != 0 && ret[n] == 0) {
        ret[n] = fib(n-1) + fib(n-2);
    }
        
    return ret[n];
}
