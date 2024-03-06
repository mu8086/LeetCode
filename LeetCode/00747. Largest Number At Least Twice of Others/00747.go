// https://leetcode.com/problems/largest-number-at-least-twice-of-others

func dominantIndex(nums []int) int {
    largest, prevLargest := 0, -1

    for i := 1; i < len(nums); i++ {
        if nums[i] >= nums[largest] {
            largest, prevLargest = i, largest
        } else if prevLargest == -1 || nums[i] > nums[prevLargest] {
            prevLargest = i
        }
    }

    if nums[prevLargest]*2 > nums[largest] {
        return -1
    }

    return largest
}
