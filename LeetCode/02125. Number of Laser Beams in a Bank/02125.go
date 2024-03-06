// https://leetcode.com/problems/number-of-laser-beams-in-a-bank

func numberOfBeams(bank []string) (sum int) {
    var zeroStr string
    for i := len(bank[0]); i > 0; i-- {
        zeroStr += string('0')
    }

    ones := func(s string) (count int) {
        if s == zeroStr {
            return 0
        }

        for _, c := range s {
            if c == '1' {
                count++
            }
        }
        return count
    }

    prev := 0
    for i, size := 0, len(bank); i < size; i++ {
        curr := ones(bank[i])
        if curr != 0 {
            if prev != 0 {
                sum += prev * curr
            }

            prev = curr
        }
    }

    return sum
}
