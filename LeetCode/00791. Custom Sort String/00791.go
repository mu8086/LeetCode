// https://leetcode.com/problems/custom-sort-string

func customSortString(order string, s string) string {
    orderM := make([]int, 26, 26)

    for i, size := 0, len(order); i < size; i++ {
        orderM[order[i]-'a'] = i
    }

    bs := []byte(s)
    sort.Slice(bs, func(i, j int) bool {
        return orderM[bs[i]-'a'] < orderM[bs[j]-'a']
    })

    return string(bs)
}
