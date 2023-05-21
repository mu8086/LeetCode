// https://leetcode.com/problems/merge-strings-alternately

func mergeAlternately(word1 string, word2 string) (s string) {
    l1, l2 := len(word1), len(word2)
    l := l1
    if l < l2 {
        l = l2
    }

    lb := l1 + l2
    b := make([]byte, lb, lb)
    for i, ib := 0, 0; i < l; i++ {
        if i < l1 {
            b[ib] = word1[i]
            ib++
        }
        if i < l2 {
            b[ib] = word2[i]
            ib++
        }
    }

    return string(b)
}
