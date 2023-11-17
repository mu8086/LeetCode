// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array

func minPairSum(nums []int) (max int) {
    sort.Ints(nums)

    last := len(nums)-1

    for i := last/2; i >= 0; i-- {
        pairSum := nums[i] + nums[last-i]
        if max < pairSum {
            max = pairSum
        }
    }

    return max
}
