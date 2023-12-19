// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence

func appendCharacters(s string, t string) int {
    sSize, tSize := len(s), len(t)

    i, j := 0, 0
    for i < tSize && j < sSize {
        if t[i] == s[j] {
            i++
        }
        j++
    }

    return tSize-i
}
