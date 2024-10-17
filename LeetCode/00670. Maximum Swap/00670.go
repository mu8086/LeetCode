// https://leetcode.com/problems/maximum-swap

func maximumSwap(num int) int {
    bs := make([]byte, 0, 0)
    m := make(map[byte]int)

    for idx := 0; num > 0; idx, num = idx+1, num/10 {
        digit := byte(num % 10)
        bs = append(bs, digit)

        if _, found := m[digit]; !found {
            m[digit] = idx
        }
    }

    for i, flag := len(bs)-1, false; i >= 0; i-- {
        digit := bs[i]

        if !flag {
            for mWalker := byte(9); mWalker > digit; mWalker-- {
                if idx, found := m[mWalker]; found && idx < i {
                    bs[idx], digit = digit, bs[idx]
                    flag = true
                    break
                }
            }
        }

        num = num*10 + int(digit)
    }
    
    return num
}
