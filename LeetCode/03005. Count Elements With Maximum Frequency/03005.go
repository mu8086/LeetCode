// https://leetcode.com/problems/count-elements-with-maximum-frequency

func maxFrequencyElements(nums []int) int {
    m := make(map[int]int)

    for i, size := 0, len(nums); i < size; i++ {
        m[nums[i]]++
    }

    ans, maxFreq := 0, 0
    for _, freq := range m {
        if maxFreq == freq {
            ans += freq
        } else if maxFreq < freq {
            maxFreq = freq
            ans = freq
        }
    }

    return ans
}
