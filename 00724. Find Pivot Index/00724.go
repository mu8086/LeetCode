// https://leetcode.com/problems/find-pivot-index

// sliding window
func pivotIndex(nums []int) int {
    size := len(nums)

    rightSum := 0
    for i := 1; i < size; i++ {
        rightSum += nums[i]
    }

    if rightSum == 0 {
        return 0
    }

    leftSum := 0
    for i := 1; i < size; i++ {
        leftSum += nums[i-1]
        rightSum -= nums[i]

        if leftSum == rightSum {
            return i
        }
    }

    return -1
}

// prefix sum
func pivotIndexPrefixSum(nums []int) int {
    size := len(nums)
    
    prefixSum := make([]int, size, size)
    prefixSum[0] = nums[0]
    for i := 1; i < size; i++ {
        prefixSum[i] = prefixSum[i-1] + nums[i]
    }

    sum := prefixSum[size-1]
    for i := 0; i < size; i++ {
        if prefixSum[i] - nums[i] == sum - prefixSum[i] {
            return i
        }
    }

    return -1
}
