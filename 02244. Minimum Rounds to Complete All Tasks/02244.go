// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks

func minimumRounds(tasks []int) int {
    dMap := make(map[int]int)

    for _, t := range tasks {
        dMap[t]++
    }

    var ans int
    for _, d := range dMap {
        if d == 1 {
            return -1
        }

        ans += d / 3
        if d % 3 != 0 {
            ans++
        }
    }

    return ans
}
