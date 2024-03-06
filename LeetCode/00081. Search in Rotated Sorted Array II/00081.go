// https://leetcode.com/problems/search-in-rotated-sorted-array-ii

func search(nums []int, target int) bool {
    var (
        i int
        l = len(nums)
    )

    if nums[0] == target {
        return true
    }

    for i = 1; i < l; i++ {
        if nums[i] == target {
            return true
        }

        if nums[i-1] > nums[i] {
            break
        }
    }

    i += sort.SearchInts(nums[i:], target)
    return i < l && nums[i] == target
}
