// https://leetcode.com/problems/move-zeroes

func moveZeroes(nums []int) {
    i, j, l := 0, 0, len(nums)
    for i < l {
        if nums[i] != 0 {
            nums[i], nums[j] = nums[j], nums[i]
            j++
        }
        i++
    }
}
