// https://leetcode.com/problems/reverse-words-in-a-string

func _reverseWords(s string) (ans string) {
    s = " " + s + " "

    for i, l, r := len(s)-1, 0, 0; i >= 1; i-- {
        if s[i] != ' ' {
            if s[i-1] == ' ' {
                l = i
                ans += " " + s[l:r]
            }
        } else {
            if s[i-1] != ' ' {
                r = i
            }
        }
    }

    return ans[1:]
}

func reverseWords(s string) (ans string) {
    fields := strings.Fields(s)
    slices.Reverse(fields)
    return strings.Join(fields, " ")
}
