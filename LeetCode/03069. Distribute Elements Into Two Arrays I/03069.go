// https://leetcode.com/problems/distribute-elements-into-two-arrays-i

func resultArray(nums []int) []int {
    arr1, arr2 := []int{nums[0]}, []int{nums[1]}
    size := len(nums)

    arr1Idx, arr2Idx := 0, 0
    for i := 2; i < size; i++ {
        if arr1[arr1Idx] > arr2[arr2Idx] {
            arr1 = append(arr1, nums[i])
            arr1Idx++
        } else {
            arr2 = append(arr2, nums[i])
            arr2Idx++
        }
    }

    arr1 = append(arr1, arr2...)
    return arr1
}
