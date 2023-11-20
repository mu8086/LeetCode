// https://leetcode.com/problems/best-poker-hand

func bestHand(ranks []int, suits []byte) string {
    if suits[0] == suits[1] && suits[0] == suits[2] && suits[0] == suits[3] && suits[0] == suits[4] {
        return "Flush"
    }

    max := 0
    arr := [14]int{}
    for i := 0; i < 5; i++ {
        arr[ranks[i]]++
        if max < arr[ranks[i]] {
            max = arr[ranks[i]]
        }
    }

    if max >= 3 {
        return "Three of a Kind"
    } else if max == 2 {
        return "Pair"
    } else {
        return "High Card"
    }
}
