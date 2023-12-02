https://leetcode.com/problems/find-words-that-can-be-formed-by-characters

func countCharacters(words []string, chars string) (sum int) {
    freqF := func(s string) []int {
        freq := make([]int, 26, 26)

        for _, c := range s {
            freq[c - 'a']++
        }

        return freq
    }

    freqChars := freqF(chars)
    tmp := make([]int, 26, 26)

    WordLoop:
    for _, word := range words {
        copy(tmp, freqChars)

        for _, c := range word {
            if tmp[c - 'a'] == 0 {
                continue WordLoop
            }

            tmp[c - 'a']--
        }

        sum += len(word)
    }

    return sum
}
