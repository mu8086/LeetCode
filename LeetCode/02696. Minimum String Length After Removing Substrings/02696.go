// https://leetcode.com/problems/minimum-string-length-after-removing-substrings

func minLength(s string) int {
    stack := make([]rune, len(s), len(s))

    i := 0
    for _, v := range s {
        if v == 'B' && i > 0 && stack[i-1] == 'A' {
            i--
        } else if v == 'D' && i > 0 && stack[i-1] == 'C' {
            i--
        } else {
            stack[i] = v
            i++
        }
    }

    return i
}
