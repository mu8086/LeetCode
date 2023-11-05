// https://leetcode.com/problems/group-anagrams

func sortedString(s string) string {
    bs := []byte(s)
    sort.Slice(bs, func (i, j int) bool {
        return bs[i] < bs[j]
    })
    return string(bs)
}

func groupAnagrams(strs []string) (ans [][]string) {
    m := make(map[string][]int)
    for idx, s := range strs {
        sorted := sortedString(s)
        m[sorted] = append(m[sorted], idx)
    }

    for _, arr := range m {
        var strSlice []string

        for _, idx := range arr {
            strSlice = append(strSlice, strs[idx])
        }

        ans = append(ans, strSlice)
    }

    return ans
}
