// https://leetcode.com/problems/find-triangular-sum-of-an-array

func triangularSum(nums []int) int {
    sum := 0
    l := len(nums)
    pascal := make([]int, l, l)

    pascal[0] = 1
    for maxIdx := 0; maxIdx < l; maxIdx++ {
        for i, a, b := 1, 1, 0; i < maxIdx; i++ {
            b = pascal[i] % 10
            pascal[i] += a
            a = b
        }
        pascal[maxIdx] = 1
    }

    for i := 0; i < l; i++ {
        sum += (nums[i] * pascal[i]) % 10
    }

    return sum % 10
}
