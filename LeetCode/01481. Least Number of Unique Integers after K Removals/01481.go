// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals

func findLeastNumOfUniqueInts(arr []int, k int) int {
    if size := len(arr); size <= k {
        return 0
    }

    freqMap := make(map[int]int)
    for _, n := range arr {
        freqMap[n]++
    }

    freqSlice := []int{}
    for _, freq := range freqMap {
        freqSlice = append(freqSlice, freq)
    }

    sort.Ints(freqSlice)

    for i, size := 0, len(freqSlice); i < size; i++ {
        k -= freqSlice[i]
        if k == 0 {
            return size-i-1
        } else if k < 0 {
            return size-i
        }
    }

    return 0
}
