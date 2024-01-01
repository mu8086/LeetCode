// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal

func makeEqual(words []string) bool {
    size := len(words)
    bs := [26]int{}

    for _, word := range words {
        for _, c := range word {
            bs[int(c-'a')]++
        }
    }

    for i := 0; i < 26; i++ {
        if bs[i] % size != 0 {
            return false
        }
    }
    return true
}
