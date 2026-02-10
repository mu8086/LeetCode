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

func prepareIdxMapV2(arr []int) map[int][]int {
    size := len(arr)
    idxMap := make(map[int][]int)
    for i := size-1 ; i >= 0; i-- {
        slice, exists := idxMap[arr[i]]
        if !exists {
            slice = make([]int, 0)
        }

        slice = append(slice, i)
        idxMap[arr[i]] = slice
    }

    return idxMap
}

func minJumpsV2(arr []int) int {
    size := len(arr)
    lastIdx := size-1
    visited := make([]bool, size)
    idxMap := prepareIdxMapV2(arr)

    queue := []int{}

    enqueue := func (idx int ) bool {
        if idx == lastIdx {
            return true
        }

        if visited[idx] {
            return false
        }
        visited[idx] = true

        queue = append(queue, idx)
        return false
    }

    stepNextFrom := func (idx int) bool {
        flag := false
        if idx > 0 {
            flag = enqueue(idx-1)
            if flag {
                return true
            }
        }
        if idx < lastIdx {
            flag = enqueue(idx+1)
            if flag {
                return true
            }
        }

        slice := idxMap[arr[idx]]
        delete(idxMap, arr[idx])
        for _, v := range slice {
            flag = enqueue(v)
            if flag {
                return true
            }
        }

        return false
    }

    flag := enqueue(0)
    if flag {
        return 0
    }

    steps := 0

    Loop:
    for qSize := len(queue); qSize > 0; qSize = len(queue) {
        for i := 0; i < qSize; i++ {
            idx := queue[i]

            flag = stepNextFrom(idx)
            if flag {
                break Loop
            }
        }

        queue = queue[qSize:]
        steps++
    }

    return steps+1
}
