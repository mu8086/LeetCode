// https://leetcode.com/problems/longest-happy-string

func longestDiverseString(a int, b int, c int) (s string) {
    type Char struct {
        count int
        char byte
    }

    first := Char{ count: a, char: 'a' }
    second := Char{ count: b, char: 'b' }
    third := Char{ count: c, char: 'c' }

    if first.count < second.count {
        first, second = second, first
    }
    if first.count < third.count {
        first, third = third, first
    }
    if second.count < third.count {
        second, third = third, second
    }

    lastChar, contiCount := byte(0), 0
    for first.count > 0 {
        if lastChar != first.char {
            contiCount = 0
        }
        if contiCount < 2 {
            lastChar = first.char
            contiCount++

            s += string(first.char)
            first.count--

            if first.count < second.count {
                first, second = second, first
                if second.count < third.count {
                    second, third = third, second
                }
            }
        } else if second.count > 0 {
            lastChar = second.char
            contiCount = 1

            s += string(second.char)
            second.count--

            if second.count < third.count {
                second, third = third, second
            }
        } else {
            break
        }
    }

    return s
}
