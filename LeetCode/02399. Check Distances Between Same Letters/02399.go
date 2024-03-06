// https://leetcode.com/problems/check-distances-between-same-letters

func checkDistances(s string, distance []int) bool {
    size, pair := len(s), len(s) >> 1

    for i := range s {
        idx := i + distance[s[i]-'a'] + 1
        if idx < size && s[i] == s[idx] {
            pair--
        }
    }

    return pair == 0
}
