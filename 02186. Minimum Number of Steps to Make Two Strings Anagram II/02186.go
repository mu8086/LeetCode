// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii

func minSteps(s string, t string) (ans int) {
    m := make(map[rune]int)

    for _, c := range s {
        m[c]++
    }
    for _, c := range t {
        m[c]--
    }

    for _, v := range m {
        if v > 0 {
            ans += v
        } else {
            ans -= v
        }
    }

    return ans
}
