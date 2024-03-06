// https://leetcode.com/problems/lexicographically-smallest-equivalent-string

func smallestEquivalentString(s1 string, s2 string, baseStr string) (ans string) {
    size := len(s1)
    runeToGroupNum := make(map[byte]int)
    groupNumToRune := make(map[int][]byte)

    groupNum := 0
    for i := 0; i < size; i++ {
        r1, r2 := s1[i], s2[i]
        r1Group, r1Exists := runeToGroupNum[r1]
        r2Group, r2Exists := runeToGroupNum[r2]
        if !r1Exists && !r2Exists {
            runeToGroupNum[r1], runeToGroupNum[r2] = groupNum, groupNum
            groupNumToRune[groupNum] = append(groupNumToRune[groupNum], r1, r2)
            groupNum++
        } else if !r1Exists {
            runeToGroupNum[r1] = r2Group
            groupNumToRune[r2Group] = append(groupNumToRune[r2Group], r1)
        } else if !r2Exists {
            runeToGroupNum[r2] = r1Group
            groupNumToRune[r1Group] = append(groupNumToRune[r1Group], r2)
        } else {
            if r1Group > r2Group {
                r1Group, r2Group = r2Group, r1Group
            }

            for _, r := range groupNumToRune[r2Group] {
                oriGroupNum := runeToGroupNum[r]
                if oriGroupNum != r1Group {
                    runeToGroupNum[r] = r1Group
                    groupNumToRune[r1Group] = append(groupNumToRune[r1Group], r)
                }
            }
        }
    }

    for groupNum, runeSlice := range groupNumToRune {
        min := runeSlice[0]
        for _, r := range runeSlice {
            if min > r {
                min = r
            }
        }
        groupNumToRune[groupNum] = []byte{min}
    }

    for _, r := range baseStr {
        if groupNum, exists := runeToGroupNum[byte(r)]; exists {
            r2 := groupNumToRune[groupNum]
            ans += string(r2[0])
        } else {
            ans += string(r)
        }
    }

    return ans
}
