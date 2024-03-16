// https://leetcode.com/problems/contiguous-array

func findMaxLength(nums []int) int {
    ans, size := 0, len(nums)
    m := make(map[int]int)
    m[0] = -1

    for i, diff := 0, 0; i < size; i++ {
        if nums[i] == 0 {
            diff++
        } else {
            diff--
        }

        if idx, exists := m[diff]; exists {
            ans = max(ans, i-idx)
        } else {
            m[diff] = i
        }
    }

    return ans
}
