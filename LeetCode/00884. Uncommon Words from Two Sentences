// https://leetcode.com/problems/uncommon-words-from-two-sentences

func uncommonFromSentences(s1 string, s2 string) (ans []string) {
    m := make(map[string]int)

    fields1 := strings.Fields(s1)
    fields2 := strings.Fields(s2)

    for _, word := range fields1 {
        m[word]++
    }

    for _, word := range fields2 {
        m[word]++
    }

    for word, count := range m {
        if count == 1 {
            ans = append(ans, word)
        }
    }

    return ans
}
