// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

func findMin(nums []int) int {
    left, right := 0, len(nums)-1

    if nums[left] <= nums[right] {
        return nums[left]
    }

    mid := left + (right-left) >> 1

    if nums[left] <= nums[mid] {
        return findMin(nums[mid+1:])
    }
    return findMin(nums[:mid+1])
}
