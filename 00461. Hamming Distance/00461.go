// https://leetcode.com/problems/hamming-distance

func hammingDistance(x int, y int) (ans int) {
    for x ^= y; x > 0; x >>= 1 {
        ans += (x & 1)
    }

    return ans
}
