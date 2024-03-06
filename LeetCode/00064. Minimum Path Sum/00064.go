// https://leetcode.com/problems/minimum-path-sum

func minPathSum(grid [][]int) int {
    row, col := len(grid), len(grid[0])
    for i := 1; i<row; i++ {
        grid[i][0] += grid[i-1][0]
    }
    for j := 1; j<col; j++ {
        grid[0][j] += grid[0][j-1]
    }

    for i := 1; i<row; i++ {
        for j := 1; j<col; j++ {
            a, b := grid[i][j-1], grid[i-1][j]
            if a < b {
                grid[i][j] += a
            } else {
                grid[i][j] += b
            }
        }
    }

    return grid[row-1][col-1]
}
