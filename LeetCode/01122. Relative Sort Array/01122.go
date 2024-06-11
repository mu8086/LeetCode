// https://leetcode.com/problems/relative-sort-array

func relativeSortArray(arr1 []int, arr2 []int) []int {
    order := make(map[int]int)

    for idx, num := range arr2 {
        order[num] = idx+1
    }

    sort.Slice(arr1, func (i, j int) bool {
        a, b := order[arr1[i]], order[arr1[j]]

        if a != 0 && b != 0 {
            return a < b
        } else if a != 0 {
            return true
        } else if b != 0 {
            return false
        } else {
            return arr1[i] < arr1[j]
        }
    })
    
    return arr1
}
