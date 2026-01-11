// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings

func minimumDeleteSum(s1, s2 string) int {
    m, n := len(s1), len(s2)
    sumMap := make([][]int, m+1)
    for i := 0; i <= m; i++ {
        sumMap[i] = make([]int, n+1)
    }

    sum := 0
    for i := 0; i < m; i++ {
        sum += int(s1[i])
    }
    for i := 0; i < n; i++ {
        sum += int(s2[i])
    }

    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if s1[i] == s2[j] {
                sumMap[i+1][j+1] = sumMap[i][j] + int(s1[i])
            } else {
                sumMap[i+1][j+1] = max(sumMap[i+1][j], sumMap[i][j+1])
            }
        }
    }

    return sum-(sumMap[m][n] << 1)
}
