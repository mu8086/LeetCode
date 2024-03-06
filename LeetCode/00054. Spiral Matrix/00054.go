// https://leetcode.com/problems/spiral-matrix

func spiralOrder(m [][]int) (n []int) {
    u, d, l, r := 0, len(m), 0, len(m[0])
    size := d * r
    n = make([]int, size, size)

    d, r = d-1, r-1
    for count := 0; count < size; {
        for i := l; i <= r && count < size; i++ {
            n[count] = m[u][i]
            count++
        }
        u++
        for i := u; i <= d && count < size; i++ {
            n[count] = m[i][r]
            count++
        }
        r--
        for i := r; i >= l && count < size; i-- {
            n[count] = m[d][i]
            count++
        }
        d--
        for i := d; i >= u && count < size; i-- {
            n[count] = m[i][l]
            count++
        }
        l++
    }

    return n
}
