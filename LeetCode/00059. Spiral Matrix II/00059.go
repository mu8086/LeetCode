// https://leetcode.com/problems/spiral-matrix-ii

func generateMatrix(n int) (m [][]int) {
    m = make([][]int, n, n)
    for i := 0; i < n; i++ {
        m[i] = make([]int, n, n)
    }

    u, d, l, r := 0, n-1, 0, n-1
    n *= n

    for c := 1; c <= n; {
        for i := l; i <= r && c <=  n; i++ {
            m[u][i] = c
            c++
        }
        u++
        for i := u; i <= d && c <= n; i++ {
            m[i][r] = c
            c++
        }
        r--
        for i := r; i >= l && c <= n; i-- {
            m[d][i] = c
            c++
        }
        d--
        for i := d; i >= u && c <= n; i-- {
            m[i][l] = c
            c++
        }
        l++
    }

    return m
}
