// https://leetcode.com/problems/maximum-strength-of-a-group

func maxStrength(nums []int) (ans int64) {
    size := len(nums)
    if size == 1 {
        return int64(nums[0])
    }

    sort.Ints(nums)

    negativeSize := sort.SearchInts(nums, 0)
    postiveIdx := sort.SearchInts(nums, 1)

    negativeSize = negativeSize & (^1)  // subtract 1, if negativeSize is odd number

    for i := 0; i < size; i++ {
        if negativeSize <= i && i < postiveIdx {    // skip unnecessary
            continue
        }

        if ans == 0 {
            ans = 1
        }

        ans *= int64(nums[i])
    }

    return ans
}
