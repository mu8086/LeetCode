// https://leetcode.com/problems/arranging-coins

func arrangeCoins(n int) int {
    i := 1
    for n >= 0 {
        n -= i
        i++
    }
    return i-2
}
