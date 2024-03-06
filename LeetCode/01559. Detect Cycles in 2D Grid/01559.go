// https://leetcode.com/problems/detect-cycles-in-2d-grid

func containsCycle(grid [][]byte) bool {
    m, n := len(grid), len(grid[0])

    isOutside := func (row, col int) bool {
        return row < 0 || row >= m || col < 0 || col >= n
    }

    isLowerLetter := func (row, col int) bool {
        return 'a' <= grid[row][col] && grid[row][col] <= 'z'
    }

    toUpper := func(c byte) byte {
        const diff byte = 'a' - 'A'
        return c - diff
    }

    var dfs func (byte, int, int, int, int) bool
    dfs = func (target byte, row, col, fromRow, fromCol int) (foundCycle bool) {
        if isOutside(row, col) {
            return false
        }

        // end recursion if different characters or same character but uppercase are found
        if target != grid[row][col] {
            return toUpper(target) == grid[row][col]
        }

        // convert to uppercase as stopping condition for recursion
        grid[row][col] = toUpper(grid[row][col])

        // skip the previous cell, then try dfs until found cycle
        if (row-1 != fromRow || col != fromCol) && !foundCycle {
            foundCycle = dfs(target, row-1, col, row, col)
        }
        if (row+1 != fromRow || col != fromCol) && !foundCycle {
            foundCycle = dfs(target, row+1, col, row, col)
        }
        if (row != fromRow || col-1 != fromCol) && !foundCycle {
            foundCycle = dfs(target, row, col-1, row, col)
        }
        if (row != fromRow || col+1 != fromCol) && !foundCycle {
            foundCycle = dfs(target, row, col+1, row, col)
        }

        return foundCycle
    }

    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if isLowerLetter(i, j) && dfs(grid[i][j], i, j, -1, -1) {
                return true
            }
        }
    }

    return false
}
