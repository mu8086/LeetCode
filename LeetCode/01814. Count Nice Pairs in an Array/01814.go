// https://leetcode.com/problems/count-nice-pairs-in-an-array

// nums[i] - rev(nums[i]) ==  nums[j] - rev(nums[j])
func countNicePairs(nums []int) (ans int) {
    rev := func (num int) (revNum int) {
        for num > 0 {
            revNum = revNum * 10 + num % 10
            num /= 10
        }
        return revNum
    }

    count := make(map[int]int)
    for i := range nums {
        count[nums[i] - rev(nums[i])]++
    }

    for _, n := range count {
        ans = (ans + n * (n-1) / 2) % 1000000007
    }

    return ans
}
