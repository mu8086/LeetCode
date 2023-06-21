// https://leetcode.com/problems/find-smallest-letter-greater-than-target

func nextGreatestLetter(letters []byte, target byte) (ans byte) {
    ans = 'z' + 1
    for _, c := range letters {
        if c > target && ans > c {
            ans = c
        }
    }
    if ans == 'z' + 1 {
        return letters[0]
    }
    return ans
}
