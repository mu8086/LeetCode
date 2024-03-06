// https://leetcode.com/problems/minimum-operations-to-write-the-letter-y-on-a-grid

func minimumOperationsToWriteY(grid [][]int) int {
    m := len(grid)
    half := m >> 1
    ans := m*m

    ySize := func(grid [][]int) (a, b, c int) {
        for i := 0; i < half; i++ {
            switch grid[i][i] {
            case 0:
                a++
            case 1:
                b++
            case 2:
                c++
            }
            
            switch grid[i][m-1-i] {
            case 0:
                a++
            case 1:
                b++
            case 2:
                c++
            }
        }
        for i := half; i < m; i++ {
            switch grid[i][half] {
            case 0:
                a++
            case 1:
                b++
            case 2:
                c++
            }
        }
        return a, b, c
    }
    
    allSize := func(grid [][]int) (a, b, c int) {
        for i := 0; i < m; i++ {
            for j := 0; j < m; j++ {
                switch grid[i][j] {
                case 0:
                    a++
                case 1:
                    b++
                case 2:
                    c++
                }
            }
        }
        return a, b, c
    }

    yA, yB, yC := ySize(grid)
    allA, allB, allC := allSize(grid)
    allA, allB, allC = allA-yA, allB-yB, allC-yC

    // Y: 0, notY: 1
    ans = min(ans, yB+yC+allA+allC)
    // Y: 0, notY: 2
    ans = min(ans, yB+yC+allA+allB)
    // Y: 1, notY: 0
    ans = min(ans, yA+yC+allB+allC)
    // Y: 1, notY: 2
    ans = min(ans, yA+yC+allA+allB)
    // Y: 2, notY: 1
    ans = min(ans, yA+yB+allA+allC)
    // Y: 2, notY: 0
    ans = min(ans, yA+yB+allB+allC)
    return ans
}
