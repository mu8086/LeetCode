// https://leetcode.com/problems/isomorphic-strings

func isIsomorphic(s string, t string) bool {
    m1 := make(map[byte]byte)
    m2 := make(map[byte]byte)

    for i := 0; i < len(s); i++ {
        if c, exist := m1[s[i]]; !exist {
            m1[s[i]] = t[i]
        } else if c != t[i] {
            return false
        }

        if c, exist := m2[t[i]]; !exist {
            m2[t[i]] = s[i]
        } else if c != s[i] {
            return false
        }
    }

    return true
}
