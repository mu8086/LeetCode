// https://leetcode.com/problems/first-unique-character-in-a-string

func firstUniqChar(s string) int {
    idx := [26]int{}
    count := [26]int{}

    for i, c := range s {
        offset := int(c - 'a')
        idx[offset], count[offset] = i+1, count[offset]+1
    }

    minIdx := 100002
    for i := 0; i < 26; i++ {
        if count[i] == 1 && minIdx > idx[i] {
            minIdx = idx[i]
        }
    }

    if minIdx == 100002 {
        return -1
    }
    return minIdx-1
}
