// https://leetcode.com/problems/palindromic-substrings

func countSubstrings(s string) (ans int) {
    size := len(s)

    // odd size
    for oddIdx := 0; oddIdx < size; oddIdx++ {
        for l, r := oddIdx, oddIdx; l >= 0 && r < size; l, r = l-1, r+1 {
            if s[l] != s[r] {
                break
            }
            ans++
        }
    }

    // even size
    for evenIdx := 1; evenIdx < size; evenIdx++ {
        for l, r := evenIdx-1, evenIdx; l >= 0 && r < size; l, r = l-1, r+1 {
            if s[l] != s[r] {
                break
            }
            ans++
        }
    }

    return ans
}
