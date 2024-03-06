// https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k

func countSubmatrices(grid [][]int, k int) int {
    m, n := len(grid), len(grid[0])
    
    if grid[0][0] > k {
        return 0
    }

    ans := 1

    for i := 1; i < m; i++ {
        grid[i][0] += grid[i-1][0]
        if grid[i][0] <= k {
            ans++
        } else {
            m = i
            break
        }
    }
    for i := 1; i < n; i++ {
        grid[0][i] += grid[0][i-1]
        if grid[0][i] <= k {
            ans++
        } else {
            n = i
            break
        }
    }

    for i := 1; i < m; i++ {
        for j := 1; j < n; j++ {
            grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1]
            if grid[i][j] <= k {
                ans++
            }
        }
    }

    return ans
}
