// https://leetcode.com/problems/apple-redistribution-into-boxes

func minimumBoxes(apple []int, capacity []int) int {
    sort.Ints(capacity)

    sum := 0
    for _, a := range apple {
        sum += a
    }

    box := 0
    size := len(capacity)
    for i := size-1; i >= 0; i-- {
        box++

        sum -= capacity[i]
        if sum > 0 {
            continue
        }

        break
    }

    return box
}
