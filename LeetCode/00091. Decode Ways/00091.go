// https://leetcode.com/problems/decode-ways

func numDecodings(s string) (ans int) {
    if s[0] == '0' {
        return 0
    }

    fib := [101]int{1, 1}
    for i := 2; i <= 100; i++ {
        fib[i] = fib[i-2] + fib[i-1]
    }

    head, ans, size := 0, 1, len(s)
    for i := 0; i < size; i++ {
        switch s[i] {
        case '0':
            if head == i {  // leading zero
                return 0
            }

            ans *= fib[i-head-1]
            head = i+1
        case '1':
        case '2':
            if i+1 < size && s[i+1] > '6' {
                ans *= fib[i-head+1]
                head = i+1
            }
        default:
            ans *= fib[i-head+1]
            head = i+1
        }
    }

    return ans * fib[size-head]
}
