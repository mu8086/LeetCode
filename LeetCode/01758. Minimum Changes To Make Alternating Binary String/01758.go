// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string

func minOperations(s string) int {
    n, size := 0, len(s)

    for i := 0; i < size; i++ {
        if (i & 1) != int(s[i] - '0') {
            n++
        }
    }

    return min(n, size-n)
}
