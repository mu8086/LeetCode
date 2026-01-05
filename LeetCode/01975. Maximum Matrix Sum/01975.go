// https://leetcode.com/problems/maximum-matrix-sum

func maxMatrixSum(matrix [][]int) int64 {
    minVal := 100000
    sum, negCount := int64(0), 0
    for _, row := range matrix {
        for _, val := range row {
            if val < 0 {
                negCount++
                val = -val
            }

            if minVal > val {
                minVal = val
            }

            sum += int64(val)
        }
    }

    if negCount & 1 == 1 {
        sum -= int64(2*minVal)
    }
    return sum
}
