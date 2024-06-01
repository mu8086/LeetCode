// https://leetcode.com/problems/score-of-a-string

func scoreOfString(s string) (ans int) {
    for i := len(s)-1; i >= 1; i-- {
        if s[i] > s[i-1] {
            ans += int(s[i] - s[i-1])
        } else {
            ans += int(s[i-1] - s[i])
        }
    }
    return ans
}
