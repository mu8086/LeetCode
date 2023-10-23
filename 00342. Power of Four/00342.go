// https://leetcode.com/problems/power-of-four

func isPowerOfFour(n int) bool {
    // if n is zero or negative, it's not a power of 4.
    if n <= 0 {
        return false
    }

    // check if n has only one '1' bit (i.e., it's a power of two).
    if n & (n-1) != 0 {
        return false
    }

    // only powers of 4, within the powers of 2 set, have a remainder of 1 when divided by 3.
    return n % 3 == 1
}
