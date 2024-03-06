// https://leetcode.com/problems/maximum-score-from-removing-stones

func maximumScore(a int, b int, c int) (score int) {
    // let a < b < c
    if a > b {
        a, b = b, a
    }
    if b > c {
        b, c = c, b
    }
    if a > b {
        a, b = b, a
    }

    sum := a+b+c
    for sum > 1 {
        if a == 0 {
            score += min(b, c)
            break
        }

        if b == c {
            a--
            b--
            sum -= 2
            score++
        } else { // b < c
            diff := c-b
            diff = min(a, diff)

            a, c = a-diff, c-diff
            sum = sum - diff - diff
            score += diff
        }
    }

    return score
}
