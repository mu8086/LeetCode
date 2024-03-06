// https://leetcode.com/problems/valid-palindrome

func isPalindrome(s string) bool {
    s = strings.Map(func (r rune) rune {
        switch {
        case unicode.IsNumber(r):
            return r
        case unicode.IsLetter(r):
            return unicode.ToLower(r)
        default:
            return -1 // drop
        }
    }, s)

    for i, j := 0, len(s)-1; i < j; i++ {
        if s[i] != s[j-i] {
            return false
        }
    }

    return true
}
