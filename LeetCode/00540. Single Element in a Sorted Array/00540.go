// https://leetcode.com/problems/single-element-in-a-sorted-array

func singleNonDuplicate(nums []int) int {
    l, r := 0, len(nums)-1

    for l < r {
        m := l + (r-l) >> 1
        if (m & 1) == 1 {
            m--
        }

        if nums[m] == nums[m+1] {
            l = m + 2
        } else {
            r = m
        }
    }

    return nums[l]
}
