// https://leetcode.com/problems/out-of-boundary-paths

func findPaths(m int, n int, maxMove int, startRow int, startColumn int) (path int) {
    step := make([][]int, m)
    for i := 0; i < m; i++ {
        step[i] = make([]int, n)
    }

    step[startRow][startColumn] = 1
    queue := [][2]int{[2]int{startRow, startColumn}}

    move := func(row, col, prev int) {
        if row < 0 || row == m || col < 0 || col == n {
            path = (path + prev) % 1000000007
        } else {
            if step[row][col] == 0 {
                queue = append(queue, [2]int{row, col})
            }
            step[row][col] = (step[row][col] + prev) % 1000000007
        }
    }

    moveFrom := func(row, col, prev int) {
        move(row-1, col, prev)
        move(row+1, col, prev)
        move(row, col-1, prev)
        move(row, col+1, prev)

        step[row][col] = 0
    }

    for maxMove > 0 {
        levelSize := len(queue)
        for i := 0; i < levelSize; i++ {
            row, col :=  queue[i][0], queue[i][1]
            moveFrom(row, col, step[row][col])
        }

        queue = queue[levelSize:]
        maxMove--
    }

    return path
}
