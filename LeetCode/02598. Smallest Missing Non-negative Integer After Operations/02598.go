// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations

func findSmallestInteger(nums []int, value int) int {
    m := make([]int, value)

    for _, n := range nums {
        m[((n % value) + value) % value]++
    }

    minVal := 0
    for val := 1; val < value; val++ {
        if m[minVal] > m[val] {
            minVal = val
        }
    }

    return minVal + m[minVal] * value
}
