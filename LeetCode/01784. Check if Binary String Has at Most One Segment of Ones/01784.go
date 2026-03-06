// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones

func checkOnesSegment0(s string) bool {
    size := len(s)

    meet0 := false
    for i := 1; i < size; i++ {
        if s[i] == '0' {
            meet0 = true
            continue
        }

        if meet0 {
            return false
        }
    }

    return true
}

func checkOnesSegment(s string) bool {
    return !strings.Contains(s, "01")
}
