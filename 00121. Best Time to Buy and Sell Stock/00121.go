// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

func maxProfit(prices []int) (ans int) {
    buy := 10000

    for _, price := range prices {
        if buy > price {
            buy = price
        } else {
            profit := price - buy
            if ans < profit {
                ans = profit
            }
        }
    }

    return ans
}
