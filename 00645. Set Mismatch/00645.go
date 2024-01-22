// https://leetcode.com/problems/set-mismatch

func findErrorNums(nums []int) []int {
    sort.Ints(nums)

    size, dup, lost := len(nums), 0, 0
    if nums[0] != 1 {
        lost = 1
    }
    for i := 1; i < size && (dup == 0 || lost == 0); i++ {
        if dup == 0 && nums[i-1] == nums[i] {
            dup = nums[i]
        }
        if lost == 0 && nums[i-1]+1 < nums[i] {
            lost = nums[i-1]+1
        }
    }
    if lost == 0 {
        lost = size
    }

    return []int{dup, lost}
}
