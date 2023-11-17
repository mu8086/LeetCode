// https://leetcode.com/problems/rotated-digits

var (
    m []int
    size int
    initialized bool
)

func isGood(n int) bool {
    rotated := false

    for n > 0 {
        digit := n % 10
        switch digit {
            case 3, 4, 7:
                return false
            case 2, 5, 6, 9:
                rotated = true
        }

        n /= 10
    }

    return rotated
}

func rotatedDigits(n int) int {
    if initialized == false {
        initialized = true

        for i := 1; i <= 10000; i++ {
            if isGood(i) {
                m = append(m, i)
            }
        }

        size = len(m)
    }

    idx := sort.SearchInts(m, n)
    if idx < size && m[idx] == n {
        idx++
    }
    return idx
}
