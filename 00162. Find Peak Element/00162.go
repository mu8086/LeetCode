// https://leetcode.com/problems/find-peak-element

func findPeakElement(nums []int) int {
    l, r := 0, len(nums)-1

    for l < r {
        mid := l + (r-l) >> 1

        if nums[mid] < nums[mid+1] {
            l = mid + 1
        } else {
            r = mid
        }
    }

    return l
}
