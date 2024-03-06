// https://leetcode.com/problems/maximum-ice-cream-bars

func maxIceCream(costs []int, coins int) (ans int) {
    size := len(costs)
    count := make([]int, 100001, 100001)

    sum, min, max := 0, costs[0], costs[0]
    for _, price := range costs {
        sum += price
        count[price]++

        if min > price {
            min = price
        }
        if max < price {
            max = price
        }
    }
    if coins >= sum {
        return size
    }

    for price := min; price <= max; price++ {
        amount := count[price]
        if amount == 0 || size == 0 {
            continue
        }

        if tmp := amount * price; coins > tmp {
            coins -= tmp
            ans += amount
            size -= amount
        } else {
            ans += coins / price
            break
        }
    }

    return ans
}
