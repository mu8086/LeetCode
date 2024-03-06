// https://leetcode.com/problems/rearrange-array-elements-by-sign

func rearrangeArray(nums []int) []int {
    pos, neg := make([]int, 0, 0), make([]int, 0, 0)

    for i, size := 0, len(nums); i < size; i++ {
        if n := nums[i]; n > 0 {
            pos = append(pos, n)
        } else {
            neg = append(neg, n)
        }
    }

    for i, size := 0, len(nums); i < size; i += 2 {
        nums[i], nums[i+1] = pos[i>>1], neg[i>>1]
    }

    return nums
}
