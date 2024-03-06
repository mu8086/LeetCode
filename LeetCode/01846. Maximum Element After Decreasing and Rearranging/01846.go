// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging

func maximumElementAfterDecrementingAndRearranging(arr []int) int {
    sort.Ints(arr)

    size := len(arr)

    arr[0] = 1
    for prev, i := arr[0], 1; i < size; prev, i = arr[i], i+1 {
        if arr[i] > prev+1 {
            arr[i] = prev+1
        }
    }

    return arr[size-1]
}
