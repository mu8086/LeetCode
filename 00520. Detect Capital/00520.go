// https://leetcode.com/problems/detect-capital/submissions

func detectCapitalUse(word string) bool {
    if len(word) == 1 {
        return true;
    }

    var isUpper = func(c byte) bool { return 'A' <= c && c <= 'Z' }

    first, second := isUpper(word[0]), isUpper(word[1])

    if !first && second {
        return false
    }

    for i := 2; i < len(word); i++ {
        if isUpper(word[i]) != second {
            return false
        }
    }

    return true
}
