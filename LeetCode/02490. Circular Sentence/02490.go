// https://leetcode.com/problems/circular-sentence

func isCircularSentence(sentence string) bool {
    fields := strings.Fields(sentence)

    lastChar := func(s string) byte {
        return s[len(s)-1]
    }

    size := len(fields)
    for i := 1; i < size; i++ {
        if lastChar(fields[i-1]) != fields[i][0] {
            return false
        }
    }

    return lastChar(fields[size-1]) == fields[0][0]
}
