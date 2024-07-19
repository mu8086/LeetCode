// https://leetcode.com/problems/lucky-numbers-in-a-matrix

func luckyNumbers (matrix [][]int) (ans []int) {
    m, n := len(matrix), len(matrix[0])
    count := make(map[int]int)

    for row := 0; row < m; row++ {
        min := matrix[row][0]
        for col := 0; col < n; col++ {
            if min > matrix[row][col] {
                min = matrix[row][col]
            }
        }

        count[min]++
    }

    for col := 0; col < n; col++ {
        max := matrix[0][col]
        for row := 0; row < m; row++ {
            if max < matrix[row][col] {
                max = matrix[row][col]
            }
        }

        if count[max] == 1 {
            ans = append(ans, max)
        }
    }

    return ans
}
