// https://leetcode.com/problems/find-first-palindromic-string-in-the-array

func firstPalindrome(words []string) string {
    isPalindrome := func(s string) bool {
        for l, r := 0, len(s)-1; l < r; l, r = l+1, r-1 {
            if s[l] != s[r] {
                return false
            }
        }
        return true
    }

    for i, size := 0, len(words); i < size; i++ {
        if isPalindrome(words[i]) {
            return words[i]
        }
    }

    return ""
}
