// https://leetcode.com/problems/find-the-difference

func findTheDifference(s string, t string) (diff byte) {
    s += string(0)
    for i := len(s)-1; i >= 0; i-- {
        diff += t[i] - s[i]
    }
    return diff
}
