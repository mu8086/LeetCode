// https://leetcode.com/problems/find-the-town-judge

func findJudge(n int, trust [][]int) int {
    size := len(trust)
    trustAnother := make([]bool, n+1, n+1)
    trustByAnother := make([]int, n+1, n+1)

    for i := 0; i < size; i++ {
        trustAnother[trust[i][0]] = true
        trustByAnother[trust[i][1]]++
    }

    judge, threshold := -1, n-1
    for i := 1; i <= n; i++ {
        if trustByAnother[i] == threshold && trustAnother[i] == false {
            if judge == -1 {
                judge = i
            } else {
                judge = -1
                break
            }
        }
    }

    return judge
}
