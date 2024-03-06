// https://leetcode.com/problems/k-radius-subarray-averages

func getAverages(nums []int, k int) (ans []int) {
    l, x := len(nums), k*2+1
    ans = make([]int, l, l)

    for i := 1; i < l; i++ {
        nums[i] += nums[i-1]
    }

    for i := 0; i < l; i++ {
        if i < k || i+k >= l {
            ans[i] = -1
            continue
        }

        if i == k {
            ans[i] = nums[i+k] / x
        } else {
            ans[i] = (nums[i+k] - nums[i-k-1]) / x
        }
    }

    return ans
}
