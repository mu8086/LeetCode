// https://leetcode.com/problems/robot-return-to-origin

func judgeCircle(moves string) bool {
    x, y := 0, 0

    for i, size := 0, len(moves); i < size; i++ {
        switch moves[i] {
        case 'D':   y--
        case 'L':   x--
        case 'R':   x++
        case 'U':   y++
        }
    }

    return x == 0 && y == 0
}
