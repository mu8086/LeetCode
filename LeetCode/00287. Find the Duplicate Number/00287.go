// https://leetcode.com/problems/find-the-duplicate-number

func findDuplicate(nums []int) int {
    m := make(map[int]bool)
    for _, num := range nums {
        if m[num] {
            return num
        }
        m[num] = true
    }
    return -1
}
