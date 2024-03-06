// https://leetcode.com/problems/backspace-string-compare

func result(s string) string {
    b := make([]byte, len(s), len(s))

    i := 0
    for _, v := range s {
        if v != '#' {
            b[i] = byte(v)
            i++
        } else if i > 0 {
            i--
        }
    }

    return string(b[:i])
}

func backspaceCompare(ss string, tt string) bool {
    return result(ss) == result(tt)
}
