// https://leetcode.com/problems/valid-parentheses

func pop(stack []byte) []byte {
    return stack[:len(stack)-1]
}

func top(stack []byte) byte {
    return stack[len(stack)-1]
}

func isValid(s string) bool {
    if len(s) % 2 != 0 {
        return false
    }

    var stack []byte
    for _, c1 := range s {
        c := byte(c1)
        switch c {
        case '(', '[', '{':
            stack = append(stack, c)
        case ')', ']', '}':
            if len(stack) == 0 {
                return false
            }
            if c == ')' {
                c++
            }
            if c-2 != top(stack) {
                return false
            }
            stack = pop(stack)
        }
    }

    return len(stack) == 0
}
