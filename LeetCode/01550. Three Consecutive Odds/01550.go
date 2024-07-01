// https://leetcode.com/problems/three-consecutive-odds

func threeConsecutiveOdds(arr []int) bool {
    size := len(arr)
    if size < 3 {
        return false
    }

    isOdd := func(n int) bool {
        return (n & 1) == 1
    }

    count := 0
    for i := 0; i < size; i++ {
        if isOdd(arr[i]) {
            count++
            if count == 3 {
                break
            }
        } else {
            count = 0
        }
    }

    return count == 3
}
