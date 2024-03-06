// https://leetcode.com/problems/pascals-triangle-ii

var pascal [][]int
var initialized bool

func getRow(rowIndex int) []int {
    if initialized == false {
        initialized = true

        pascal = append(pascal, []int{1}, []int{1, 1})

        for i := 2; i <= 33; i++ {
            tmp := make([]int, i+1, i+1)
            tmp[0], tmp[i] = 1, 1
            for j := 1; j < i; j++ {
                tmp[j] = pascal[i-1][j-1] + pascal[i-1][j]
            }

            pascal = append(pascal, tmp)
        }
    }

    return pascal[rowIndex]
}
