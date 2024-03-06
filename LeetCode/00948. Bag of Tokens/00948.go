// https://leetcode.com/problems/bag-of-tokens

func bagOfTokensScore(tokens []int, power int) int {
    sort.Ints(tokens)

    score, l, r := 0, 0, len(tokens)-1
    for l <= r {
        if power >= tokens[l] { // can play Face-up
            score++
            power -= tokens[l]
            l++
        } else if l < r && score > 0 {  // can play Face-down, and has opportunity to get more scores
            score--
            power += tokens[r]
            r--
        } else {    // end
            break
        }
    }

    return score
}
