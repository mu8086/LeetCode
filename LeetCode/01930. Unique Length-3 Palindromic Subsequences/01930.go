// https://leetcode.com/problems/unique-length-3-palindromic-subsequences

func countPalindromicSubsequence(s string) (count int) {
    m := make(map[rune][]int)

    for idx, r := range s {
        m[r] = append(m[r], idx)
    }

    for outerLetter, outerSlice := range m {
        oSize := len(outerSlice)
        if oSize < 2 {   // can not use this letter to form string like "a-a"
            continue
        } else if oSize >= 3 {  // can use this letter to form string like "aaa"
            count++
        }

        left, right := outerSlice[0], outerSlice[oSize-1]

        for innerLetter, innerSlice := range m {
            if innerLetter == outerLetter { // already count this case
                continue
            }

            innerIdx := sort.SearchInts(innerSlice, left)

            // if innerSlice has an idx between outerSlice's begin and end
            if innerIdx < len(innerSlice) && left < innerSlice[innerIdx] && innerSlice[innerIdx] < right {
                count++
            }
        }
    }

    return count
}
