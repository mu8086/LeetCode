// https://leetcode.com/problems/determine-if-two-strings-are-close

func closeStrings(word1 string, word2 string) bool {
    if len(word1) != len(word2) {
        return false
    }

    var freq1, freq2 [26]int

    for i := len(word1)-1; i >= 0; i-- {
        freq1[int(word1[i]-'a')]++
        freq2[int(word2[i]-'a')]++
    }

    for i := 0; i < 26; i++ {
        if freq1[i] == 0 && freq2[i] != 0 || freq1[i] != 0 && freq2[i] == 0 {
            return false
        }
    }

    sort.Ints(freq1[:])
    sort.Ints(freq2[:])

    return freq1 == freq2
}
