// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array

func getSumAbsoluteDifferences(nums []int) []int {
    size := len(nums)
    prefix := make([]int, size, size)
    prefix[0] = nums[0]

    for i := 1; i < size; i++ {
        prefix[i] = prefix[i-1] + nums[i]
    }

    nums[0] = prefix[size-1] - nums[0] * size
    for i, lastIdx, totalSum := 1, size-1, prefix[size-1]; i < size; i++ {
        lSize, rSize := i, lastIdx-i

        lDiff := lSize * nums[i] - prefix[i-1]
        rDiff := totalSum - prefix[i] - rSize * nums[i]

        nums[i] = lDiff + rDiff
    }

    return nums
}
