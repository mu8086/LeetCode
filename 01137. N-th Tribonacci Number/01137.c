int tribonacci(int n){
    static int arr[38] = {0, 1, 1, 2};
    
    if (n >= 4 && arr[n] == 0) {
        for (int i=4, count=2; i<38; ++i) {
            count += arr[i-1] - arr[i-4];
            arr[i] = count;
        }
    }
    
    return arr[n];
}
