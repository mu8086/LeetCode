// https://leetcode.com/problems/maximum-odd-binary-number

func maximumOddBinaryNumber(s string) (ans string) {
    size := len(s)
    bs := make([]byte, size, size)

    ones := 0
    for i := 0; i < size; i++ {
        if s[i] == '1' {
            ones++
        }
    }

    ones, bs[size-1] = ones-1, '1'

    for i := 0; i < ones; i++ {
        bs[i] = '1'
    }

    for i := size-2; i >= ones; i-- {
        bs[i] = '0'
    }

    return string(bs)
}
