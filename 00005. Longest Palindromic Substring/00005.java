class Solution {
    private int head, maxLen;
    
    public String longestPalindrome(String s) {
        int length = s.length();
        
        if (length == 1) {
            return s;
        }
        
        for (int i = length-2; i >= 0; i--) {
            extendPalindrome(s, i, i);
            if (s.charAt(i) == s.charAt(i+1)) {
                extendPalindrome(s, i, i+1);
            }
        }
        
        return s.substring(head, head + maxLen);
    }
    
    public void extendPalindrome(String s, int i, int j) {
        while (i >= 0 && j < s.length() && s.charAt(i) == s.charAt(j)) {
            i--;
            j++;
        }
        // valid palindrome: (i+1) ~ (j-1)
        // (j-1) - (i+1) + 1
        if (maxLen < j-i-1) {
            maxLen = j-i-1;
            head = i+1;
        }
    }
}
