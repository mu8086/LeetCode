// https://leetcode.com/problems/find-the-integer-added-to-array-i

func addedInteger(nums1 []int, nums2 []int) int {
    sort.Ints(nums1)
    sort.Ints(nums2)
    return nums2[0] - nums1[0]
}
