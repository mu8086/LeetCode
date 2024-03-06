// https://leetcode.com/problems/lexicographically-smallest-palindrome

func makeSmallestPalindrome(s string) string {
    rs := make([]byte, len(s), len(s))
    for i, j := 0, len(s)-1; i <= j; i, j = i+1, j-1 {
        if s[i] != s[j] && s[i] > s[j] {
            rs[i], rs[j] = s[j], s[j]
        } else {
            rs[i], rs[j] = s[i], s[i]
        }
    }
    return string(rs)
}
