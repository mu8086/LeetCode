// https://leetcode.com/problems/binary-number-with-alternating-bits

func hasAlternatingBits(n int) bool {
    for prev := ((^n) & 1); n > 0; n >>= 1 {
        if (n & 1) == prev {
            return false
        }

        prev = n & 1
    }
    return true
}
