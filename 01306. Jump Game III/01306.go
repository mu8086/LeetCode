// https://leetcode.com/problems/jump-game-iii

func canReach(arr []int, start int) bool {
    l := len(arr)
    queue := []int{start}
    visited := make([]bool, l, l)
    for levelSize := len(queue); levelSize > 0; levelSize = len(queue) {
        for i := 0; i < levelSize; i++ {
            idx := queue[i]
            if visited[idx] {
                continue
            }
            visited[idx] = true

            if arr[idx] == 0 {
                return true
            } else {
                left, right := idx-arr[idx], idx+arr[idx]
                if left >= 0 {
                    queue = append(queue, left)
                }
                if right < l {
                    queue = append(queue, right)
                }
            }
        }

        queue = queue[levelSize:]
    }

    return false
}
