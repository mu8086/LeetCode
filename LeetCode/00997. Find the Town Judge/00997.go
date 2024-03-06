// https://leetcode.com/problems/find-the-town-judge

func findJudge(n int, trust [][]int) int {
    trustAnother := make([]bool, n+1, n+1)
    trustByAnother := make([]int, n+1, n+1)

    judge := 1
    maxTrustByAnother := 0
    for i, size := 0, len(trust); i < size; i++ {
        trustAnother[trust[i][0]] = true
        trustByAnother[trust[i][1]]++

        if maxTrustByAnother < trustByAnother[trust[i][1]] {
            judge = trust[i][1]
            maxTrustByAnother = trustByAnother[trust[i][1]]
        }
    }

    if trustAnother[judge] == false && trustByAnother[judge] == n-1 {
        return judge
    }
    return -1
}
