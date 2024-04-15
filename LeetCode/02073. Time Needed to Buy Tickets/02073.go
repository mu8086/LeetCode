// https://leetcode.com/problems/time-needed-to-buy-tickets

func timeRequiredToBuy(tickets []int, k int) (ans int) {
    for i, size := 0, len(tickets); ; i = (i+1) % size {
        if tickets[i] > 0 {
            tickets[i]--
            ans++

            if i == k && tickets[i] == 0 {
                break
            }
        }
    }
    return ans
}
