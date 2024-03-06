// https://leetcode.com/problems/equal-row-and-column-pairs

func equalPairs(grid [][]int) (count int) {
    m := make(map[[200]int]int)
    rowSize, colSize := len(grid), len(grid[0])

    tmp := [200]int{}
    for i := 0; i < rowSize; i++ {
        copy(tmp[:], grid[i])
        m[tmp]++
    }
    for j := 0; j < colSize; j++ {
        for i := 0; i < rowSize; i++ {
            tmp[i] = grid[i][j]
        }

        if v := m[tmp]; v > 0 {
            count += v
        }
    }

    return count
}
