// https://leetcode.com/problems/surrounded-regions

type point struct {
    x int
    y int
}

func solve(board [][]byte)  {
    l := list.New()

    m, n := len(board), len(board[0])
    
    isValidPoint := func (y, x int) bool {
        return 0 <= x && x < n && 0 <= y && y < m
    }

    enQueue := func(y, x int) {
        board[y][x] = '-'
        l.PushBack(&point{y: y, x: x})
    }

    for i := 0; i < n; i++ {
        if board[0][i] == 'O' {
            enQueue(0, i)
        }

        if m > 1 && board[m-1][i] == 'O' {
            enQueue(m-1, i)
        }
    }

    for i := m-2; i >= 1; i-- {
        if board[i][0] == 'O' {
            enQueue(i, 0)
        }

        if n > 1 && board[i][n-1] == 'O' {
            enQueue(i, n-1)
        }
    }

    for l.Len() > 0 {
        pop := l.Remove(l.Front()).(*point)
        y, x := pop.y, pop.x

        if isValidPoint(y-1, x) && board[y-1][x] == 'O' {
            enQueue(y-1, x)
        }

        if isValidPoint(y+1, x) && board[y+1][x] == 'O' {
            enQueue(y+1, x)
        }

        if isValidPoint(y, x-1) && board[y][x-1] == 'O' {
            enQueue(y, x-1)
        }

        if isValidPoint(y, x+1) && board[y][x+1] == 'O' {
            enQueue(y, x+1)
        }
    }

    for i := range board {
        for j := range board[i] {
            if board[i][j] == 'O' {
                board[i][j] = 'X'
            } else if board[i][j] == '-' {
                board[i][j] = 'O'
            }
        }
    }
}
