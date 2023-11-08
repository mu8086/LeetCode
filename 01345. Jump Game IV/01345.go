// https://leetcode.com/problems/jump-game-iv

func minJumps(arr []int) (step int) {
    l := len(arr)
    queue := []int{0}
    idxMap := make(map[int][]int)    // key: arr[i], value: index slice of same arr[i] value
    visited := make([]bool, l, l)

    for i := l-1; i >= 0; i-- {
        idxMap[arr[i]] = append(idxMap[arr[i]], i)
    }

    Loop:
    for levelSize := len(queue); levelSize > 0; levelSize = len(queue) {
        for i := 0; i < levelSize; i++ {
            idx := queue[i]
            if idx == l-1 {
                break Loop
            }

            if visited[idx] {
                continue
            }
            visited[idx] = true

            if idx+1 < l {
                queue = append(queue, idx+1)
            }
            if idx-1 >= 0 {
                queue = append(queue, idx-1)
            }

            if idxSlice, exists := idxMap[arr[idx]]; exists {
                queue = append(queue, idxSlice...)
                delete(idxMap, arr[idx])
            }
        }
        step++
        queue = queue[levelSize:]
    }

    return step
}
