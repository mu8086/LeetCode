// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends

func minimumLength(s string) int {
    l, r := 0, len(s)-1

    for l < r && s[l] == s[r] {
        targetL, targetR := s[l], s[r]

        for l = l+1; l < r; l++ {
            if targetL != s[l] {
                break
            }
        }

        for r = r-1; l < r; r-- {
            if targetR != s[r] {
                break
            }
        }
    }

    return r-l+1
}
