// https://leetcode.com/problems/determine-if-string-halves-are-alike

func isVowel(c byte) bool {
    switch c {
        case 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U':
            return true
    }
    return false
}

func halvesAreAlike(s string) bool {
    a, b := 0, 0
    
    bs := []byte(s)
    
    for _, c := range bs[:(len(s)/2)] {
        if isVowel(c) {
            a++
        }
    }
    
    for _, c := range bs[(len(s)/2):] {
        if isVowel(c) {
            b++
        }
    }
    
    return a == b
}
