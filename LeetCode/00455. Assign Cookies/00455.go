// https://leetcode.com/problems/assign-cookies

func findContentChildren(g []int, s []int) int {
    gIdx, gSize, sIdx, sSize := 0, len(g), 0, len(s)

    sort.Ints(s)
    sort.Ints(g)

    for sIdx < sSize && gIdx < gSize {
        if s[sIdx] >= g[gIdx] {
            gIdx++
        }

        sIdx++
    }

    return gIdx
}
