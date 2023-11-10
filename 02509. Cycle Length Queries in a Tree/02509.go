// https://leetcode.com/problems/cycle-length-queries-in-a-tree

func getCommonRoot(a, b int) int {
    m := map[int]bool{ 1: true }

    for a > 1 {
        m[a] = true
        a >>= 1
    }

    for b > 1 && m[b] == false {
        b >>= 1
    }

    return b
}

func depth(n, root int) (d int) {
    for n > root {
        n >>= 1
        d++
    }
    return d
}

func cycleLengthQueries(n int, queries [][]int) []int {
    l := len(queries)
    ans := make([]int, l, l)

    for i := 0; i < l; i++ {
        root := getCommonRoot(queries[i][0], queries[i][1])
        ans[i] = depth(queries[i][0], root) + depth(queries[i][1], root) + 1
    }

    return ans
}
