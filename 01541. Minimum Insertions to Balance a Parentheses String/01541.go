// https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string

func minInsertions(s string) (ans int) {
    left, right := 0, 0

    add := func(c byte) {
        if c == '(' {
            left++
        } else {
            right++
        }
    }

    insert := func() {
        ans += right & 1
        right = 0

        if left > 0 {
            left--
        } else {
            ans++
        }
    }

    for i, size := 0, len(s); i < size; i++ {
        if right & 1 == 0 {
            add(s[i])
        } else {
            if s[i] == '(' {
                insert()
                add(s[i])
            } else {
                add(s[i])
                insert()
            }
        }
    }

    if right > 0 {
        insert()
    }

    return ans + left*2
}
