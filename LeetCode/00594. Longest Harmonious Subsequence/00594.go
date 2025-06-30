// https://leetcode.com/problems/longest-harmonious-subsequence

func findLHS(nums []int) int {
    m := make(map[int]int, len(nums))

    for _, n := range nums {
        m[n]++
    }

    maxLen := 0
    for n, count := range m {
        neighborCount := m[n+1]
        if neighborCount == 0 {
            continue
        }

        if maxLen < count+neighborCount {
            maxLen = count+neighborCount
        }
    }

    return maxLen
}
