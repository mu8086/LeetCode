// https://leetcode.com/problems/find-the-substring-with-maximum-cost

func maximumCostSubstring(s string, chars string, vals []int) int {
    m := [26]int{}

    for i := 0; i < 26; i++ {
        m[i] = i+1
    }

    for i, c := range chars {
        m[c - 'a'] = vals[i]
    }

    max, count := 0, 0
    for lIdx, rIdx, size := 0, 0, len(s); rIdx < size; rIdx++ {
        count += m[s[rIdx] - 'a']

        for count < 0 {
            count -= m[s[lIdx] - 'a']
            lIdx++
        }

        if max < count {
            max = count
        }
    }

    return max
}
