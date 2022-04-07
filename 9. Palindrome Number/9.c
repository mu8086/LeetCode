bool isPalindrome(int x){
    unsigned int tmp = 0, y = x;
    
    if (x < 0)
        return false;

    if (y) {
        tmp = y % 10;
        y /= 10;
    }
    
    while (y) {
        tmp *= 10;
        tmp += y % 10;
        y /= 10;
    }
    
    if (tmp == x)
        return true;
    return false;
}
