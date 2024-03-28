// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency

func maxSubarrayLength(nums []int, k int) int {
    ans := 0
    freq := make(map[int]int)

    for l, r, size := 0, 0, len(nums); r < size; r++ {
        n := nums[r]

        if freq[n] < k {
            freq[n]++
        } else {
            for l < r {
                if nums[l] == n {
                    l++
                    break
                }

                freq[nums[l]]--
                l++
            }
        }

        ans = max(ans, r-l+1)
    }

    return ans
}
