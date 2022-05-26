int tribonacci(int n){
    static int arr[38] = {0, 1, 1};
    
    if (n >= 3 && arr[n] == 0) {
        arr[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
    
    return arr[n];
}
