// https://leetcode.com/problems/n-repeated-element-in-size-2n-array

func repeatedNTimes(nums []int) int {
    freq := make(map[int]int)
    for _, n := range nums {
        freq[n]++
        if freq[n] > 1 {
            return n
        }
    }

    return -1
}
