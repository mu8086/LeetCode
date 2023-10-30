// https://leetcode.com/problems/move-zeroes

func moveZeroes(nums []int) {
    i, j, l := 0, 0, len(nums)
    for i < l {
        if nums[i] == 0 {
            for j = i+1; j < l; j++ {
                nums[j-1] = nums[j]
            }
            l--
            nums[l] = 0
        } else {
            i++
        }
    }
}
