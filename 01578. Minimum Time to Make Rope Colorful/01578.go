// https://leetcode.com/problems/minimum-time-to-make-rope-colorful

func minCost(colors string, neededTime []int) (ans int) {
    var (
        sumTime, maxTime int
        prevColor byte
    )

    for i, size := 0, len(colors); i < size; i++ {
        if prevColor == colors[i] {
            sumTime += neededTime[i]
            maxTime = max(maxTime, neededTime[i])
        } else {
            ans += sumTime - maxTime

            prevColor = colors[i]
            sumTime = neededTime[i]
            maxTime = neededTime[i]
        }
    }

    return ans + sumTime - maxTime
}
