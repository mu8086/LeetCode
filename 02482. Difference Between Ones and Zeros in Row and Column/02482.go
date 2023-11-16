// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column

func onesMinusZeros(grid [][]int) [][]int {
    rowSize, colSize := len(grid), len(grid[0])

    onesRow := make([]int, rowSize, rowSize)
    onesCol := make([]int, colSize, colSize)

    for i := 0; i < rowSize; i++ {
        for j := 0; j < colSize; j++ {
            if grid[i][j] == 1 {
                onesRow[i]++
                onesCol[j]++
            }
        }
    }

    diff := make([][]int, rowSize, rowSize)
    for i := 0; i < rowSize; i++ {
        diff[i] = make([]int, colSize, colSize)
        for j := 0; j < colSize; j++ {
            diff[i][j] = onesRow[i] - (rowSize - onesRow[i]) + onesCol[j] - (colSize - onesCol[j])
        }
    }

    return diff
}
