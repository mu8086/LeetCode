// https://leetcode.com/problems/path-crossing

func isPathCrossing(path string) bool {
    m := make(map[[2]int]bool)
    m[[2]int{0, 0}] = true

    for i, size, x, y := 0, len(path), 0, 0; i < size; i++ {
        switch path[i] {
        case 'N':   y++
        case 'S':   y--
        case 'E':   x++
        case 'W':   x--
        }

        if m[[2]int{x, y}] {
            return true
        }
        m[[2]int{x, y}] = true
    }

    return false
}
