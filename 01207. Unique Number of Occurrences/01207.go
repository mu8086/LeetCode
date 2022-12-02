// https://leetcode.com/problems/unique-number-of-occurrences

func uniqueOccurrences(arr []int) bool {
    freq := make(map[int]int)
    freqMap := make(map[int]bool)
    
    for _, vArr := range arr {
        freq[vArr]++
    }

    for _, vFreq := range freq {
        if freqMap[vFreq] != false {
            return false
        }
        freqMap[vFreq] = true
    }
    
    return true
}
