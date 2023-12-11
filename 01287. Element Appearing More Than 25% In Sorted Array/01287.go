// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array

func findSpecialInteger(arr []int) int {
    size := len(arr)

    for i, count, threshold := 1, 1, size >> 2; i < size; i++ {
        if arr[i-1] == arr[i] {
            count++
            if count > threshold {
                return arr[i]
            }
        } else {
            count = 1
        }
    }

    return arr[0]
}
