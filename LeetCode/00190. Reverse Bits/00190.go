// https://leetcode.com/problems/reverse-bits

func reverseBits(num uint32) (ans uint32) {
    for i := 0; i < 32; i++ {
        ans <<= 1
        ans += (num & 1)
        num >>= 1
    }

    return ans
}
