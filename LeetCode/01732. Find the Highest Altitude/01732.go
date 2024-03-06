// https://leetcode.com/problems/find-the-highest-altitude

func largestAltitude(gain []int) int {
    max, curr := 0, 0
    for _, n := range gain {
        curr += n
        if max < curr {
            max = curr
        }
    }
    return max
}
