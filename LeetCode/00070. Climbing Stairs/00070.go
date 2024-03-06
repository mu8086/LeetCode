// https://leetcode.com/problems/climbing-stairs

func climbStairs(n int) int {
    m := make([]int, n+1)
    
    m[0], m[1] = 1, 1
    for i := 2; i <= n; i++ {
        m[i] = m[i-2] + m[i-1]
    }
    return m[n]
}
