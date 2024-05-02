// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative

func findMaxK(nums []int) int {
    ans := -1
    m := make(map[int]bool)

    for _, num := range nums {
        m[num] = true
    }

    for num := range m {
        if num > 0 && m[-num] {
            ans = max(ans, num)
        }
    }

    return ans
}
