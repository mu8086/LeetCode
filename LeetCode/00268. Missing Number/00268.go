// https://leetcode.com/problems/missing-number

func missingNumber(nums []int) int {
    sum := (len(nums) * (len(nums)+1)) >> 1
    for _, num := range nums {
        sum -= num
    }
    return sum
}
