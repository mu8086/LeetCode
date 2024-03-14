// https://leetcode.com/problems/palindrome-number

class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int rev = 0, tmp = x;
        
        while (tmp > 0) {
            rev = rev * 10 + tmp % 10;
            tmp /= 10;
        }

        return rev == x;
    }
}
