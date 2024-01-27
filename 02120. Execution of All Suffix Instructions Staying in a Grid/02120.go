// https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid

func executeInstructions(n int, startPos []int, s string) (ans []int) {
    for i, size := 0, len(s); i < size; i++ {
        row, col, count := startPos[0], startPos[1], 0
        for j := i; j < size; j++ {
            switch s[j] {
            case 'D':   row++
            case 'L':   col--
            case 'R':   col++
            case 'U':   row--
            }

            if row < 0 || row == n || col < 0 || col == n {
                break
            }
            count++
        }
        
        ans = append(ans, count)
    }
    
    return ans
}
