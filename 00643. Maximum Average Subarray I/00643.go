// https://leetcode.com/problems/maximum-average-subarray-i

func findMaxAverage(nums []int, k int) float64 {
    sum := 0
    for i := 0; i < k; i++ {
        sum += nums[i]
    }

    maxSum := sum

    size := len(nums)-k
    for i := 0; i < size; i++ {
        sum = sum - nums[i] + nums[i+k]

        if maxSum < sum {
            maxSum = sum
        }
    }

    return float64(maxSum) / float64(k)
}
