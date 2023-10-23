// https://leetcode.com/problems/power-of-four

func isPowerOfFour(n int) bool {
    if n <= 0 {
        return false
    }

    for (n & 3) == 0 {
        n >>= 2
    }

    return n == 1
}
