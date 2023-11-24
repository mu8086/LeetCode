// https://leetcode.com/problems/maximum-number-of-coins-you-can-get

func maxCoins(piles []int) int {
    sort.Ints(piles)

    coins, size := 0, len(piles)

    for i := size/3; i < size; i += 2 {
        coins += piles[i]
    }

    return coins
}
