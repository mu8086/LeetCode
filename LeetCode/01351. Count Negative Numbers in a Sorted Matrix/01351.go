// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

func countNegatives(grid [][]int) (ans int) {
    for row := range grid {
        for col := len(grid[row])-1; col >= 0; col-- {
            if grid[row][col] < 0 {
                ans++
            } else {
                break
            }
        }
    }
    return ans
}
