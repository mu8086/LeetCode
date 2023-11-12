// https://leetcode.com/problems/minimum-score-by-changing-two-elements

func minimizeSum(nums []int) int {
    size := len(nums)

    sort.Ints(nums)

    return min(nums[size-3]-nums[0], min(nums[size-2]-nums[1], nums[size-1]-nums[2]))
}
