// https://leetcode.com/problems/maximum-score-after-splitting-a-string

func maxScore(s string) (max int) {
    lastIdx := len(s)-1

    lSize, rSize := 0, 0
    for i := 0; i <= lastIdx; i++ {
        if s[i] == '1' {
            rSize++
        }
    }

    if s[0] == '1' {
        rSize--
    } else {
        lSize++
    }
    max = lSize + rSize

    for i := 1; i < lastIdx; i++ {
        if s[i] == '1' {
            rSize--
        } else {
            lSize++

            if max < lSize + rSize {
                max = lSize + rSize
            }
        }
    }

    return max
}
