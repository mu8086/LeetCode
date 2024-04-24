// https://leetcode.com/problems/n-th-tribonacci-number

var once bool
var arr [38]int

func tribonacci(n int) int {
    if once == false {
        once = true

        arr[0], arr[1], arr[2] = 0, 1, 1
        for i := 3; i < 38; i++ {
            arr[i] = arr[i-3] + arr[i-2] + arr[i-1]
        }
    }

    return arr[n]
}
