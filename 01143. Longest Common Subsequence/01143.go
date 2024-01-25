// https://leetcode.com/problems/longest-common-subsequence

func longestCommonSubsequence(text1 string, text2 string) int {
    size1, size2 := len(text1), len(text2)
    m := make([][]int, size1+1)
    for i := 0; i <= size1; i++ {
        m[i] = make([]int, size2+1)
    }

    for i := 0; i < size1; i++ {
        for j := 0; j < size2; j++ {
            if text1[i] == text2[j] {
                m[i+1][j+1] = m[i][j]+1
            } else {
                m[i+1][j+1] = max(max(m[i][j], m[i+1][j]), m[i][j+1])
            }
        }
    }

    return m[size1][size2]
}
