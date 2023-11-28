// https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor

func numberOfWays(corridor string) int {
    sIdx := []int{}

    for idx, r := range corridor {
        if r == 'S' {
            sIdx = append(sIdx, idx)
        }
    }

    if len(sIdx) == 0 {
        return 0
    } else if (len(sIdx) & 1) == 1 {   // odd size Seat
        return 0
    }

    ans := 1
    for i := len(sIdx)-2; i > 1; i -= 2 {
        ans = ans * (sIdx[i]-sIdx[i-1]) % 1000000007
    }

    return ans
}
