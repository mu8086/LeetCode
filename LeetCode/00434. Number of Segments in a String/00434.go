// https://leetcode.com/problems/number-of-segments-in-a-string

func countSegments(s string) (count int) {
    isSpace := true

    for _, c := range s {
        if c != ' ' {
            if isSpace {
                count++
            }
            isSpace = false
        } else {
            isSpace = true
        }
    }

    return count
}
