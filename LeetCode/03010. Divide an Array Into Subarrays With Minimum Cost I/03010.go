// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i

func minimumCost(nums []int) int {
    sort.Ints(nums[1:])
    return nums[0] + nums[1] + nums[2]
}
