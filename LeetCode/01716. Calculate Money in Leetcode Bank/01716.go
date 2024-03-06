// https://leetcode.com/problems/calculate-money-in-leetcode-bank

func totalMoney(n int) (ans int) {
    week, day := n / 7, n % 7

    if week > 0 {
        ans += (week + 7) * 7 * week
    }

    return (ans + ((1+day) + week*2)*day) / 2
}
