// https://leetcode.com/problems/make-the-string-great

func makeGood(s string) string {
    size := len(s)
    bs := make([]byte, size+1, size+1)

    match := func(a, b byte) bool {
        const offset = 'a' - 'A'

        if 'a' <= a && a <= 'z' {
            if 'A' <= b && b <= 'Z' {
                return a - b == offset
            }
        } else if 'A' <= a && a <= 'Z' {
            if 'a' <= b && b <= 'z' {
                return b - a == offset
            }
        }
        return false
    }

    bsIdx := 0
    bs[0] = ' '
    for i := 0; i < size; i++ {
        if match(bs[bsIdx], s[i]) {
            bsIdx--
        } else {
            bsIdx++
            bs[bsIdx] = s[i]
        }
    }

    return string(bs[1:bsIdx+1])
}
