// https://leetcode.com/problems/count-number-of-bad-pairs

// i - nums[i] != j - nums[j]
func countBadPairs(nums []int) (count int64) {
    m := make(map[int]int)

    for i := range nums {
        count += int64(i - m[i - nums[i]])
        m[i - nums[i]]++
    }

    return count
}
