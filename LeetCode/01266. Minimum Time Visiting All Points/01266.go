// https://leetcode.com/problems/minimum-time-visiting-all-points

func minTimeToVisitAllPoints(points [][]int) (ans int) {
    x, y := points[0][0], points[0][1]
    size := len(points)

    for i := 1; i < size; i++ {
        xx, yy := points[i][0], points[i][1]

        diffX, diffY := xx-x, yy-y
        if diffX < 0 {
            diffX = -diffX
        }
        if diffY < 0 {
            diffY = -diffY
        }

        ans += max(diffX, diffY)

        x, y = xx, yy
    }

    return ans
}
