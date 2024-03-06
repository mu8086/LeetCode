// https://leetcode.com/problems/counting-bits

func numOf1Bits(n int) (ans int) {
    for n > 0 {
        ans += (n & 1)
        n >>= 1
    }
    return ans
}

func countBits(n int) (ans []int) {
    for i := 0; i <= n; i++ {
        ans = append(ans, numOf1Bits(i))
    }
    return ans
}
