// https://leetcode.com/problems/matrix-diagonal-sum

func diagonalSum(mat [][]int) int {
    ans, size := 0, len(mat)
    if size % 2 == 1 {
        ans -= mat[size/2][size/2]
    }

    for i := 0; i < size; i++ {
        ans += mat[i][i] + mat[i][size-1-i]
    }

    return ans
}
