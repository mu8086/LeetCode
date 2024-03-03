// https://leetcode.com/problems/split-the-array

func isPossibleToSplit(nums []int) bool {
    m := make(map[int]int)
    for _, num := range nums {
        m[num]++
        if m[num] == 3 {
            return false
        }
    }
    return true
}
