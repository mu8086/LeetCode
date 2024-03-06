// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c

func minFlips(a int, b int, c int) (ans int) {
    for i, xor := 0, (a|b) ^ c; i < 32; i++ {
        if ((xor >> i) & 1) == 0 {
            continue
        }

        if ((c >> i) & 1) == 0 {
            if ((a >> i) & 1) == 1 {
                ans++
            }
            if ((b >> i) & 1) == 1 {
                ans++
            }
        } else {
            ans++
        }
    }
    return ans
}
