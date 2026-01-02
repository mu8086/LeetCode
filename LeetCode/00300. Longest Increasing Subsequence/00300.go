// https://leetcode.com/problems/longest-increasing-subsequence

func lengthOfLIS(nums []int) int {
    sz := len(nums)
    dp := make([]int, sz)
    for i := 0; i < sz; i++ {
        dp[i] = 1
        for j := 0; j < i; j++ {
            if nums[i] > nums[j] && dp[i] < dp[j]+1 {
                dp[i] = dp[j]+1
            }
        }
    }

    ans := 0
    for i := 0; i < sz; i++ {
        if ans < dp[i] {
            ans = dp[i]
        }
    }

    return ans
}
