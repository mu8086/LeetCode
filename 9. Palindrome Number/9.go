func isPalindrome(x int) bool {
    if x < 0 {
        return false
    }

    s := strconv.Itoa(x)
    size := len(s)
    half := size/2

    for i, j:=0, size-1; i<=half; i++ {
        if s[i] != s[j-i] {
            return false
        }
    }

    return true
}
