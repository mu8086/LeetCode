// https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time

func isReachableAtTime(sx int, sy int, fx int, fy int, t int) bool {
    x, y := (fx-sx), (fy-sy)
    if x < 0 {
        x = -x
    }
    if y < 0 {
        y = -y
    }
    if x + y == 0 && t == 1 {
        return false
    }

    // refactor same logic to "max(x, y) <= t"
    /*
        leftDistance := x-y
        diagonalSteps := y
        if leftDistance < 0 {
            leftDistance = -leftDistance
            diagonalSteps = x
        }

        return diagonalSteps + leftDistance <= t
    */

    // x = max(x, y)
    if x < y {
        x = y
    }
    return x <= t
}
