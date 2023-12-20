// https://leetcode.com/problems/buy-two-chocolates

func buyChoco(prices []int, money int) int {
    sort.Ints(prices)
    if money >= prices[0]+prices[1] {
        money -= prices[0]+prices[1]
    }
    return money
}
