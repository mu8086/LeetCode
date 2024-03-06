// https://leetcode.com/problems/count-number-of-homogenous-substrings

func countHomogenous(s string) (ans int) {
    var (
        modulo = 1000000007
        prev byte
        start, i int
        l = len(s)
    )

    for i = 0; i < l; i++ {
        if prev != s[i] {
            ans += ((1+i-start)*(i-start)/2) % modulo
            start = i
            
            prev = s[i]
        }
    }

    ans += ((1+l-start)*(l-start)/2) % modulo

    return ans
}
