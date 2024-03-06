// https://leetcode.com/problems/removing-stars-from-a-string/

func removeStars(s string) string {
    var stack []rune

    for _, r := range s {
        if r == '*' {
            stack = stack[:len(stack)-1]
        } else {
            stack = append(stack, r)
        }
    }
    
    return string(stack[:])
}
