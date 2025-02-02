// https://leetcode.com/problems/special-array-i

func isArraySpecial(nums []int) bool {
    for i, size := 1, len(nums); i < size; i++ {
        if ((nums[i-1] + nums[i]) & 1) == 0 {
            return false
        }
    }
    return true
}
