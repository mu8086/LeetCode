// https://leetcode.com/problems/power-of-two

func isPowerOfTwo(n int) bool {
    if n < 1 {
        return false
    }

    // check if n has only one '1' bit (i.e., it's a power of two).
    return (n & (n-1)) == 0
}
