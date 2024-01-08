// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid

func findMaxFish(grid [][]int) (ans int) {
    rowSize, colSize := len(grid), len(grid[0])

    isOutside := func(row, col int) bool {
        return row < 0 || row >= rowSize || col < 0 || col >= colSize
    }

    var dfs func(i, j int) int
    dfs = func(i, j int) (sum int) {
        if isOutside(i, j) || grid[i][j] == 0 {
            return 0
        }

        sum, grid[i][j] = grid[i][j], 0

        return sum + dfs(i-1, j) + dfs(i+1, j) + dfs(i, j-1) + dfs(i, j+1)
    }

    for i := 0; i < rowSize; i++ {
        for j := 0; j < colSize; j++ {
            if grid[i][j] != 0 {
                if sum := dfs(i, j); ans < sum {
                    ans = sum
                }
            }
        }
    }

    return ans
}
