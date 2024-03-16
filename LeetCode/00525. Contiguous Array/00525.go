// https://leetcode.com/problems/contiguous-array

func findMaxLength(nums []int) int {
    ans, size := 0, len(nums)
    m := make(map[int]int)
    m[0] = -1

    for i, sum := 0, 0; i < size; i++ {
        if nums[i] == 0 {
            sum++
        } else {
            sum--
        }

        if idx, exists := m[sum]; exists {
            ans = max(ans, i-idx)
        } else {
            m[sum] = i
        }
    }

    return ans
}
