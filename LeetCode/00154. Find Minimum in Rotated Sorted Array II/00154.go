// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii

func findSliceMin(nums []int) (min int) {
    min = nums[0]
    for i := len(nums)-1; i >= 1; i-- {
        if min > nums[i] {
            min = nums[i]
        }
    }
    return min
}

func findMin(nums []int) int {
    left, right := 0, len(nums)-1
    if nums[left] == nums[right] {
        return findSliceMin(nums)
    }

    continueLoop := true
    for left < right && nums[left] > nums[right] && continueLoop {
        mid := left + (right-left)>>1
        if mid == left {
            continueLoop = false
        }

        if nums[mid] > nums[left] {
            left = mid+1
        } else if nums[mid] < nums[left] {
            right = mid
        } else {
            left = mid
        }
    }

    if nums[right] < nums[left] {
        return nums[right]
    }
    return nums[left]
}
