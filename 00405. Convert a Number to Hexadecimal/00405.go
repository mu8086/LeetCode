// https://leetcode.com/problems/convert-a-number-to-hexadecimal

func toHex(num int) (s string) {
    if num == 0 {
        return "0"
    }

    var (
        n = uint32(num)

        hex = []string{
            "0", "1", "2", "3", "4", "5", "6", "7",
            "8", "9", "a", "b", "c", "d", "e", "f"}
    )

    for n != 0 {
        s = hex[n & 15] + s
        n >>= 4
    }

    return s
}
