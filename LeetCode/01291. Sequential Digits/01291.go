// https://leetcode.com/problems/sequential-digits

func sequentialDigits(low int, high int) (ans []int) {
    digits := func(n int) (d int) {
        for n > 0 {
            n, d = n/10, d+1
        }
        return d
    }

    leadingNum := func(d int) (num int) {
        for i := 1; d > 0; i, d = i+1, d-1 {
            num = num * 10 + i
        }
        return num
    }

    incrementN := func(d int) (n int) {
        for d > 0 {
            n = n * 10 + 1
            d--
        }
        return n
    }

    for d, dMax := digits(low), digits(high); d <= dMax; d++ {
        n, increment := leadingNum(d), incrementN(d)
        for i, round := 0, 10-d; i < round && n <= high; i++ {
            if low <= n {
                ans = append(ans, n)
            }
            n += increment
        }
    }

    return ans
}
