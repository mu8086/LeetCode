// https://leetcode.com/problems/house-robber-ii

func rob(nums []int) int {
    size := len(nums)
    if size == 1 {
        return nums[0]
    } else if size == 2 {
        return max(nums[0], nums[1])
    } else if size == 3 {
        return max(nums[0], max(nums[1], nums[2]))
    }

    nums2 := make([]int, size-1)
    copy(nums2, nums[:size-1])
    yes1 := helper(nums2)
    no1 := helper(nums[1:])

    return max(yes1, no1)
}

func helper(nums []int) int {
    size := len(nums)
    if size == 1 {
        return nums[0]
    } else if size == 2 {
        return max(nums[0], nums[1])
    } else if size == 3 {
        return max(nums[0]+nums[2], nums[1])
    }

    nums[2] += nums[0]
    for i := 3; i < size; i++ {
        nums[i] += max(nums[i-3], nums[i-2])
    }

    return max(nums[size-2], nums[size-1])
}
