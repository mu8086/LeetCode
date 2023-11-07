// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

func removeDuplicates(nums []int) (validIdx int) {
    for i, l, times := 1, len(nums), 1; i < l; i++ {
        if nums[i] == nums[validIdx] {
            times++
        } else {
            times = 1
        }

        if times <= 2 {
            validIdx++
            nums[validIdx] = nums[i]
        }
    }

    return validIdx+1
}
