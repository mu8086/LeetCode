// https://leetcode.com/problems/squares-of-a-sorted-array

func sortedSquares(nums []int) []int {
    for i := len(nums)-1; i >= 0; i-- {
        nums[i] *= nums[i]
    }

    sort.Ints(nums)

    return nums
}
