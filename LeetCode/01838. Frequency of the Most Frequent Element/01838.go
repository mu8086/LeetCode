// https://leetcode.com/problems/frequency-of-the-most-frequent-element

func maxFrequency(nums []int, k int) int {
    sort.Ints(nums)

    left := 0
    prefixSum := 0

    // window: [left - right]
    for right := 0; right < len(nums); right++ {
        currStep := nums[right]
        prefixSum += currStep

        // check all elements in window can reach to current target step/level;
        // if not, enter to the `if case`
        if (right-left+1) * currStep - prefixSum > k {
            prefixSum -= nums[left]
            left++
        }
    }

    // `right-left` is the largest valid window size
    // after the loop, `right` is same to the `len(nums)`
    return len(nums) - left
}
