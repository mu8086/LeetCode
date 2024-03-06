// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points

func maxWidthOfVerticalArea(points [][]int) int {
    sort.Slice(points, func(i, j int) bool {
        return points[i][0] < points[j][0]
    })

    max, size := points[1][0] - points[0][0], len(points)
    for i := 2; i < size; i++ {
        diff := points[i][0] - points[i-1][0]
        if max < diff {
            max = diff
        }
    }

    return max
}
