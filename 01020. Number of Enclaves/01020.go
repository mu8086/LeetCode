// https://leetcode.com/problems/number-of-enclaves

func numEnclaves(grid [][]int) int {
    lastRow, lastCol := len(grid)-1, len(grid[0])-1    
    
    for j := 0; j <= lastCol; j++ {
        zeroify(grid, lastRow, lastCol, 0, j)
        zeroify(grid, lastRow, lastCol, lastRow, j)
    }
    
    for i := 1; i < lastRow; i++ {
        zeroify(grid, lastRow, lastCol, i, 0)
        zeroify(grid, lastRow, lastCol, i, lastCol)
    }
    
    return countOne(grid)
}

func zeroify(grid [][]int, lastRow, lastCol, row, col int) {
    if row < 0 || row > lastRow || col < 0 || col > lastCol {
        return
    }

    if (grid[row][col] == 0) {
        return
    }

    grid[row][col] = 0

    zeroify(grid, lastRow, lastCol, row-1, col)
    zeroify(grid, lastRow, lastCol, row+1, col)
    zeroify(grid, lastRow, lastCol, row, col-1)
    zeroify(grid, lastRow, lastCol, row, col+1)
}

func countOne(grid [][]int) (count int) {
    lastRow, lastCol := len(grid)-1, len(grid[0])-1

    for i := lastRow-1; i >= 1; i-- {
        for j := lastCol-1; j >= 1; j-- {
            if (grid[i][j] == 1) {
                count++
            }
        }
    }

    return count
}
