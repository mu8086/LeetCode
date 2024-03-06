// https://leetcode.com/problems/number-of-islands

func numIslands(grid [][]byte) (count int) {
    var (
        m, n = len(grid), len(grid[0])
        dfs func (int, int)
    )

    dfs = func (i, j int) {
        if i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' {
            return
        }

        grid[i][j] = '0'

        dfs(i-1, j)
        dfs(i+1, j)
        dfs(i, j-1)
        dfs(i, j+1)
    }

    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if grid[i][j] == '1' {
                count++
                dfs(i, j)
            }
        }
    }

    return count
}
