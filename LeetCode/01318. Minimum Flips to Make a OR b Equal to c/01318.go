// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c

func minFlips(a, b, c int) int {
    xor := (a|b)^c

    count := 0
    for offset := 0; xor > 0; offset++ {
        if (xor & 1) != 0 {
            count += flipTimes(a, b, c, offset)
        }

        xor >>= 1
    }

    return count
}

func flipTimes(a, b, c, offset int) int {
    a = (a >> offset) & 1
    b = (b >> offset) & 1
    c = (c >> offset) & 1

    if c == 1 {
        return 1
    }
    return a+b
}
