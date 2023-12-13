// https://leetcode.com/problems/special-positions-in-a-binary-matrix

func numSpecial(mat [][]int) (ans int) {
    rowSize, colSize := len(mat), len(mat[0])
    rowCount := make([]int, rowSize)
    colCount := make([]int, colSize)

    for i := 0; i < rowSize; i++ {
        for j := 0; j < colSize; j++ {
            if mat[i][j] == 1 {
                rowCount[i]++
                colCount[j]++
            }
        }
    }

    for i := 0; i < rowSize; i++ {
        for j := 0; j < colSize; j++ {
            if mat[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1 {
                ans++
            }
        }
    }

    return ans
}
