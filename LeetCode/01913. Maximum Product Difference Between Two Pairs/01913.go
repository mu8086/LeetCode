// https://leetcode.com/problems/maximum-product-difference-between-two-pairs

func maxProductDifference(nums []int) int {
    sort.Ints(nums)
    return nums[len(nums)-1] * nums[len(nums)-2] - nums[1] * nums[0]
}
