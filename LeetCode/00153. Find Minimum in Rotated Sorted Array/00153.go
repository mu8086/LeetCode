// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

func findMin(nums []int) int {
    left, right := 0, len(nums)-1

    for left < right && nums[left] > nums[right] {
        mid := left + (right-left)>>1

        if nums[mid] >= nums[left] {
            left = mid+1
        } else {
            right = mid
        }
    }

    return nums[left]
}

// recursive
func _findMin(nums []int) int {
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
