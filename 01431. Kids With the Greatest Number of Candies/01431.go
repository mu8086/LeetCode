// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

func kidsWithCandies(candy []int, extra int) (result []bool) {
    result = make([]bool, len(candy), len(candy))

    max := 0
    for i := range candy {
        if max < candy[i] {
            max = candy[i]
        }
    }

    for i := range candy {
        result[i] = (candy[i] + extra >= max)
    }

    return result
}
