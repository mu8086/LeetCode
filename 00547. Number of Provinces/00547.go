// https://leetcode.com/problems/number-of-provinces

func findCircleNum(isConnected [][]int) int {
    n := len(isConnected)
    visited := make([]bool, n, n)

    var dfs func(int)
    dfs = func(i int) {
        visited[i] = true

        for j := 0; j < n; j++ {
            if visited[j] {
                continue
            }

            if isConnected[i][j] == 1 {
                dfs(j)
            }
        }
    }

    count := 0
    for i := 0; i < n; i++ {
        if visited[i] == false {
            dfs(i)
            count++
        }
    }

    return count
}
