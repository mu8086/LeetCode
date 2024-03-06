// https://leetcode.com/problems/count-of-matches-in-tournament

func numberOfMatches(n int) (ans int) {
    for n > 1 {
        ans += (n >> 1) + (n & 1)
        n >>= 1
    }
    
    return ans
}

// another version
func numberOfMatches2(n int) int {
    return n-1
}
