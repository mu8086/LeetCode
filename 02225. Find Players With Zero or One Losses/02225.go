// https://leetcode.com/problems/find-players-with-zero-or-one-losses

func findWinners(matches [][]int) [][]int {
    ans := make([][]int, 2, 2)
    loseMap := make(map[int]int)

    for _, match := range matches {
        if _, exists := loseMap[match[0]]; !exists {
            loseMap[match[0]] = 0
        }
        loseMap[match[1]]++
    }

    for player, lose := range loseMap {
        if lose <= 1 {
            ans[lose] = append(ans[lose], player)
        }
    }

    sort.Ints(ans[0])
    sort.Ints(ans[1])
    return ans
}
