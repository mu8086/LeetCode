// https://leetcode.com/problems/xor-operation-in-an-array

func xorOperation(n int, start int) (ans int) {
    for ; n > 0; n-- {
        ans ^= start
        start += 2
    }
    return ans
}
