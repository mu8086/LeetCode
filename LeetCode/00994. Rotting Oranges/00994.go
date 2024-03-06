// https://leetcode.com/problems/rotting-oranges

func orangesRotting(grid [][]int) (count int) {
    const (
        fresh = 1
        rotten = 2
    )

    freshSize := 0
    queue := []int{}
    rowSize, colSize := len(grid), len(grid[0])

    linearIdx := func (row, col int) int { return row * colSize + col }

    oriIdx := func (idx int) (int, int) { return idx / colSize, idx % colSize }

    isFresh := func (row, col int) bool {
        return 0 <= row && row < rowSize && 0 <= col && col < colSize && grid[row][col] == fresh
    }

    infect := func (row, col int) {
        if isFresh(row, col) {
            grid[row][col] = rotten
            freshSize--

            idx := linearIdx(row, col)
            queue = append(queue, idx)
        }
    }

    for i := 0; i < rowSize; i++ {
        for j := 0; j < colSize; j++ {
            if grid[i][j] == fresh {
                freshSize++
            } else if grid[i][j] == rotten {
                queue = append(queue, linearIdx(i, j))
            }
        }
    }

    if freshSize == 0 {
        return 0
    }

    for levelSize := len(queue); levelSize > 0; levelSize = len(queue) {
        count++

        for i := 0; i < levelSize; i++ {
            row, col := oriIdx(queue[i])

            grid[row][col] = rotten

            infect(row-1, col)
            infect(row+1, col)
            infect(row, col-1)
            infect(row, col+1)
        }

        queue = queue[levelSize:]
    }

    if freshSize > 0 {
        return -1
    }
    return count-1  // remove the initial step
}
