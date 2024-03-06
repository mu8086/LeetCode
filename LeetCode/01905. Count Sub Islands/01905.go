// https://leetcode.com/problems/count-sub-islands

func countSubIslands(grid1 [][]int, grid2 [][]int) (count int) {
    var (
        m, n = len(grid2), len(grid2[0])
        isSubIsland func(int, int) bool
    )

    isSubIsland = func(i, j int) bool {
        if i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0 {
            return true
        }

        grid2[i][j] = 0

        res := isSubIsland(i-1, j)
        res = isSubIsland(i+1, j) && res
        res = isSubIsland(i, j-1) && res
        res = isSubIsland(i, j+1) && res

        if grid1[i][j] == 0 {
            return false
        }

        return res
    }

    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if grid2[i][j] == 1 && isSubIsland(i, j) {
                count++
            }
        }
    }

    return count
}
