// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent

func arrayStringsAreEqual(word1 []string, word2 []string) bool {
    return strings.Join(word1, "") == strings.Join(word2, "")
}
