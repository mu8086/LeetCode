// https://leetcode.com/problems/eliminate-maximum-number-of-monsters

func eliminateMaximum(dist []int, speed []int) (count int) {
    l := len(dist)
    minutes := make([]int, l, l)

    for i := 0; i < l; i++ {
        minutes[i] = dist[i] / speed[i]
        if dist[i] % speed[i] != 0 {
            minutes[i]++
        }
    }

    sort.Ints(minutes)

    for i := 0; i < l; i++ {
        if i >= minutes[i] {
            break
        }
        count++
    }

    return count
}
