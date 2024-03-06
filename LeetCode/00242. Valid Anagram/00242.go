// https://leetcode.com/problems/valid-anagram

func isAnagram(s string, t string) bool {
    sSize, tSize := len(s), len(t)
    if sSize != tSize {
        return false
    }

    sArr, tArr := [26]int{}, [26]int{}
    for i := 0; i < sSize; i++ {
        sArr[s[i]-'a']++
        tArr[t[i]-'a']++
    }

    return sArr == tArr
}
