// https://leetcode.com/problems/minimum-falling-path-sum

func minFallingPathSum(matrix [][]int) int {
    n := len(matrix)
    if n == 1 {
        return matrix[0][0]
    }

    nextRow := func(i, j int) int {
        if j == 0 {
            return min(matrix[i+1][j], matrix[i+1][j+1])
        } else if j == n-1 {
            return min(matrix[i+1][j-1], matrix[i+1][j])
        } else {
            return min(min(matrix[i+1][j-1], matrix[i+1][j]), matrix[i+1][j+1])
        }
    }

    for row := n-2; row > 0; row-- {
        for col := 0; col < n; col++ {
            matrix[row][col] += nextRow(row, col)
        }
    }

    min := 10000
    for col := 0; col < n; col++ {
        if sum := matrix[0][col] + nextRow(0, col); min > sum {
            min = sum
        }
    }
    return min
}
