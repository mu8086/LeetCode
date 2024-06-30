// https://leetcode.com/problems/maximum-total-importance-of-roads

func maximumImportance(n int, roads [][]int) int64 {
    times := make([]int, n, n)

    for _, road := range roads {
        times[road[0]]++
        times[road[1]]++
    }

    sort.Ints(times)

    ans := int64(0)
    for i := int64(n-1); i >= 0; i-- {
        ans += int64(times[i]) * (i+1)
    }

    return ans
}
