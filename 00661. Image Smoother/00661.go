// https://leetcode.com/problems/image-smoother

func imageSmoother(img [][]int) [][]int {
    m, n := len(img), len(img[0])

    ans := make([][]int, m, m)
    for i := 0; i < m; i++ {
        ans[i] = make([]int, n, n)
    }
    
    surroundingSum := func(i, j int) (sum int) {
        for row := max(i-1, 0); row <= min(i+1, m-1); row++ {
            for col := max(j-1, 0); col <= min(j+1, n-1); col++ {
                sum += img[row][col]
            }
        }
        return sum
    }

    surroundingSize := func(i, j int) (size int) {
        return (min(i+1, m-1)-max(i-1, 0)+1) * (min(j+1, n-1)-max(j-1, 0)+1)
    }

    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            ans[i][j] = surroundingSum(i, j)
        }
    }

    if m < 3 || n < 3 {
        for i := 0; i < m; i++ {
            for j := 0; j < n; j++ {
                ans[i][j] /= surroundingSize(i, j)
            }
        }
        return ans
    }

    ans[0][0] /= 4
    ans[0][n-1] /= 4
    ans[m-1][0] /= 4
    ans[m-1][n-1] /= 4

    for i := m-2; i >= 1; i-- {
        ans[i][0] /= 6
        ans[i][n-1] /= 6
    }

    for j := n-2; j >= 1; j-- {
        ans[0][j] /= 6
        ans[m-1][j] /= 6
    }

    for i := m-2; i >= 1; i-- {
        for j := n-2; j >= 1; j-- {
            ans[i][j] /= 9
        }
    }

    return ans
}
