// https://leetcode.com/problems/is-subsequence

func isSubsequence(s string, t string) bool {
    idxS, idxT := 0, 0
    lenS, lenT := len(s), len(t)

    for idxS < lenS && idxT < lenT {
        if s[idxS] == t[idxT] {
            idxS++
        }
        idxT++
    }

    return idxS == lenS
}
