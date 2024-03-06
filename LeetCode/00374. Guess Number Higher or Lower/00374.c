// https://leetcode.com/problems/guess-number-higher-or-lower

int guessNumber(int n) {
    int l = 1, r = n, guessResult;
    
    while ((guessResult = guess(n)) != 0) {
        if (guessResult == -1) {
            r = n;
        } else {
            l = n;
        }
        n = l + (r-l) / 2;
    }
    
	return n;
}
