// https://leetcode.com/problems/island-perimeter

func islandPerimeter(grid [][]int) (ans int) {
    m, n := len(grid), len(grid[0])

    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if grid[i][j] == 0 {
                continue
            }

            if i-1 < 0 || grid[i-1][j] == 0 {
                ans++
            }
            if i+1 >= m || grid[i+1][j] == 0 {
                ans++
            }
            if j-1 < 0 || grid[i][j-1] == 0 {
                ans++
            }
            if j+1 >= n || grid[i][j+1] == 0 {
                ans++
            }
        }
    }

    return ans
}
