// https://leetcode.com/problems/set-matrix-zeroes

func setZeroes(matrix [][]int)  {
    i, j := 0, 0
    m, n := len(matrix), len(matrix[0])
    row, col := make([]bool, m), make([]bool, n)

    for i = 0; i < m; i++ {
        for j = 0; j < n; j++ {
            if matrix[i][j] == 0 {
                row[i], col[j] = true, true
            }
        }
    }

    for i = 0; i < m; i++ {
        if row[i] {
            for j = 0; j < n; j++ {
                matrix[i][j] = 0
            }
        }
    }

    for j = 0; j < n; j++ {
        if col[j] {
            for i = 0; i < m; i++ {
                matrix[i][j] = 0
            }
        }
    }
}
