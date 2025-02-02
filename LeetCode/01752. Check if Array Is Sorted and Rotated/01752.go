// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

func check(nums []int) bool {
    for i, size, lead, flag := 1, len(nums), nums[0], false; i < size; i++ {
        if flag == false {
            if nums[i-1] <= nums[i] {
                continue
            }

            flag = true

            if nums[size-1] > lead {
                return false
            }
        } else if nums[i-1] > nums[i] {
            return false
        }
    }

    return true
}
