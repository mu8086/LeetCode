bool isHappy(int n) {
    if (n == 1 || n == 7) {
        return true;
    } else if (n == 0 || n < 10) {
        return false;
    }
    
    int sum, digit;

    for (sum = 0; n > 0; n /= 10) {
        digit = n % 10;
        sum += (digit * digit);
    }

    return isHappy(sum);
}
