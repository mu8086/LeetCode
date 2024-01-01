// https://leetcode.com/problems/largest-substring-between-two-equal-characters

func maxLengthBetweenEqualCharacters(s string) int {
    max := -1
    m := [26]int{}

    for i, c := range s {
        idx := c-'a'
        if m[idx] == 0 {
            m[idx] = i+1
        } else {
            if max < i - m[idx] {
                max = i - m[idx]
            }
        }
    }

    return max
}
