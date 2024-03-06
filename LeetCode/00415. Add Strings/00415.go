// https://leetcode.com/problems/add-strings

func reverse(digits []byte) (s string) {
    for i := len(digits)-1; i >= 0; i-- {
        s += fmt.Sprintf("%v", digits[i])
    }
    return s
}

func addStrings(n1 string, n2 string) string {
    len1, len2 := len(n1), len(n2)

    // let n1 is longer string
    if len1 < len2 {
        n1, n2 = n2, n1
        len1, len2 = len2, len1
    }

    digits := make([]byte, len1+1, len1+1)

    // i indicates farFromEnd
    for i := 0; i < len1; i++ {
        if i < len2 {
            digits[i] += n2[len2-1-i] - '0'
        }
        digits[i] += n1[len1-1-i] - '0'

        if digits[i] > 9 {
            digits[i] -= 10
            digits[i+1]++
        }
    }
    if digits[len1] == 0 {
        digits = digits[:len1]
    }

    return reverse(digits)
}
