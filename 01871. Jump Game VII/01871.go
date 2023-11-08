// https://leetcode.com/problems/jump-game-vii

func canReach(s string, minJump int, maxJump int) bool {
    l := len(s)
    if s[l-1] != '0' {
        return false
    }

    zero := []int{}
    for i := 1; i < l; i++ {
        if s[i] == '0' {
            zero = append(zero, i)
        }
    }

    queue := []int{0}
    zeroIdx, zeroSize := 0, len(zero)
    for levelSize := len(queue); levelSize > 0; levelSize = len(queue) {
        for i := 0; i < levelSize; i++ {
            left, right := queue[i]+minJump, queue[i]+maxJump

            for zeroIdx < zeroSize {
                idx := zero[zeroIdx]
                if left <= idx && idx <= right {
                    if idx == l-1 {
                        return true
                    }
                    queue = append(queue, idx)
                } else if idx > right {
                    break
                }
                zeroIdx++
            }
        }
        queue = queue[levelSize:]
    }

    return false
}
