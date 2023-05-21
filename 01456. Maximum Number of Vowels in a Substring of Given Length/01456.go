// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

func isVowel(c byte) bool {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
}

func maxVowels(s string, k int) int {
    vowels := 0
    for i := 0; i < k; i++ {
        if isVowel(s[i]) {
            vowels++
        }
    }
    max := vowels
    
    for i := k; i < len(s); i++ {
        if isVowel(s[i-k]) {
            vowels--
        }
        if isVowel(s[i]) {
            vowels++
            if max < vowels {
                max = vowels
            }
        }
    }

    return max
}
