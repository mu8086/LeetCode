// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

func nearestExit(maze [][]byte, entrance []int) (ans int) {
    lastRow, lastCol := len(maze)-1, len(maze[0])-1

    isOutside := func(row, col int) bool {
        return row < 0 || row > lastRow || col < 0 || col > lastCol
    }

    maze[entrance[0]][entrance[1]] = '+'
    queue := [][2]int{[2]int{entrance[0], entrance[1]}}

    addToQueue := func(row, col int) {
        if isOutside(row, col) {
           return 
        }

        if maze[row][col] == '.' {
            maze[row][col] = '+'
            queue = append(queue, [2]int{row, col})
        }
    }

    for qSize := len(queue); qSize > 0; qSize = len(queue) {
        for i := 0; i < qSize; i++ {
            row, col := queue[i][0], queue[i][1]

            if row == 0 || col == 0 || row == lastRow || col == lastCol {
                if row != entrance[0] || col != entrance[1] {
                    return ans
                }
            }

            addToQueue(row-1, col)
            addToQueue(row+1, col)
            addToQueue(row, col-1)
            addToQueue(row, col+1)
        }

        ans++
        queue = queue[qSize:]
    }

    return -1
}
