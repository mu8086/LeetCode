// https://leetcode.com/problems/string-compression

func compress(chars []byte) (ans int) {
    slice := []byte{}
    size := len(chars)
    prevChar, prevHead := chars[0], 0

    newChar := func(c byte) bool {
        return c != prevChar
    }

    getDigitSlice := func(n int) (bs []byte) {
        if n == 1 {
            return
        }
        for n > 0 {
            bs = append(bs, byte((n % 10) + '0'))
            n /= 10
        }

        slices.Reverse(bs)
        return bs
    }

    for i := 1; i < size; i++ {
        if newChar(chars[i]) {
            digitSlice := getDigitSlice(i - prevHead)

            slice = append(slice, prevChar)
            slice = append(slice, digitSlice...)

            prevChar, prevHead = chars[i], i
        }
    }

    digitSlice := getDigitSlice(size - prevHead)

    slice = append(slice, prevChar)
    slice = append(slice, digitSlice...)

    copy(chars, slice)

    return len(slice)
}
