// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i

func minOperations(nums []int, k int) int {
    sort.Ints(nums)
    return sort.SearchInts(nums, k)
}
