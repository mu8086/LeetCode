// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit

func minMaxDifference(num int) int {
    s := strconv.Itoa(num)

    first := ""
    for _, c := range s {
        if c != '9' {
            first = string(c)
            break
        }
    }

    max := num
    if first != "" {
        max, _ = strconv.Atoi(strings.ReplaceAll(s, first, "9"))
    }

    min, _ := strconv.Atoi(strings.ReplaceAll(s, string(s[0]), "0"))

    return max - min
}
