// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

func nearestExit(maze [][]byte, entrance []int) int {
    m, n := len(maze), len(maze[0])

    const (
        WALL = '+'
        EMPTY = '.'
    )

    type Point struct {
        y int
        x int
    }
    queue := make([]Point, 0)

    enqueue := func(y, x int) {
        maze[y][x] = WALL
        queue = append(queue, Point{ y: y, x: x })
    }

    stepTo := func(y, x int) bool {
        if y < 0 || y >= m || x < 0 || x >= n || maze[y][x] == WALL {
            return false
        }

        enqueue(y, x)
        return true
    }

    isBorder := func (y, x int) bool {
        return y == 0 || y == m-1 || x == 0 || x == n-1
    }

    enqueue(entrance[0], entrance[1])

    steps := 1
    for qSize := len(queue); qSize > 0; qSize = len(queue) {
        for i := 0; i < qSize; i++ {
            p := queue[i]

            if (stepTo(p.y-1, p.x) && isBorder(p.y-1, p.x)) || 
                (stepTo(p.y+1, p.x) && isBorder(p.y+1, p.x)) ||
                (stepTo(p.y, p.x-1) && isBorder(p.y, p.x-1)) ||
                (stepTo(p.y, p.x+1) && isBorder(p.y, p.x+1)) {
                return steps
            }
        }

        queue = queue[qSize:]
        steps++
    }

    return -1
}
