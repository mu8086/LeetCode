// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence

func canMakeArithmeticProgression(arr []int) bool {
    sort.Ints(arr)

    for i, diff := 2, arr[1]-arr[0]; i < len(arr); i++ {
        if arr[i-1] + diff != arr[i] {
            return false
        }
    }

    return true
}
