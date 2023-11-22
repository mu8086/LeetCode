// https://leetcode.com/problems/diagonal-traverse-ii

func findDiagonalOrder(nums [][]int) (ans []int) {
    diagonal := make(map[int][]int)

    for i, m := 0, len(nums); i < m; i++ {
        for j, n := 0, len(nums[i]); j < n; j++ {
            diagonal[i+j] = append(diagonal[i+j], nums[i][j])
        }
    }

    for ij := 0; ; ij++ {
        if slice, exists := diagonal[ij]; exists {
            for i := len(slice)-1; i >= 0; i-- {
                ans = append(ans, slice[i])
            }
        } else {
            break
        }
    }

    return ans
}
