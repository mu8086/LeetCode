// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal

func reductionOperations(nums []int) (ans int) {
    sort.Ints(nums)

    size := len(nums)
    for i := sort.SearchInts(nums, nums[size-1]); i > 0; i = sort.SearchInts(nums, nums[i-1]) {
        ans += size-i
    }

    return ans
}
