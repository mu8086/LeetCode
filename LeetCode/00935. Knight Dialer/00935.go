// https://leetcode.com/problems/knight-dialer

func knightDialer(n int) int {
    sum := func(arr [10]int) (ret int) {
        for i := range arr {
            ret = (ret + arr[i]) % 1000000007
        }
        return ret
    }

    end := [10]int{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

    for i := 1; i < n; i++ {
        tmp := [10]int{
            end[4] + end[6],
            end[6] + end[8],
            end[7] + end[9],
            end[4] + end[8],
            end[0] + end[3] + end[9],
            0, 
            end[0] + end[1] + end[7],
            end[2] + end[6],
            end[1] + end[3],
            end[2] + end[4],
        }

        for i := range tmp {
            end[i] = tmp[i] % 1000000007
        }
    }

    return sum(end)
}
