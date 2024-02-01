// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference

func divideArray(nums []int, k int) (ans [][]int) {
    sort.Ints(nums)

    for i, size := 2, len(nums); i < size; i += 3 {
        if nums[i-2] + k >= nums[i] {
            ans = append(ans, []int{nums[i-2], nums[i-1], nums[i]})
        } else {
            return nil
        }
    }

    return ans
}
