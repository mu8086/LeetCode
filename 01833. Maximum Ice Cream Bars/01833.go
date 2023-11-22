// https://leetcode.com/problems/maximum-ice-cream-bars

func maxIceCream(costs []int, coins int) (ans int) {
    count := make([]int, 100001, 100001)

    min, max := costs[0], costs[0]
    for _, price := range costs {
        count[price]++

        if min > price {
            min = price
        }
        if max < price {
            max = price
        }
    }

    for price := min; price <= max; price++ {
        amount := count[price]
        if amount == 0 {
            continue
        }

        if tmp := amount * price; coins > tmp {
            coins -= tmp
            ans += amount
        } else {
            ans += coins / price
            break
        }
    }

    return ans
}
