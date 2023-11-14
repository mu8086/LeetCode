// https://leetcode.com/problems/largest-number

func largestNumber(nums []int) (ans string) {
    size := len(nums)
    slice := make([]string, size, size)

    for i := 0; i < size; i++ {
        slice[i] = strconv.Itoa(nums[i])
    }

    sort.Slice(slice, func (i, j int) bool {
        ij, ji := slice[i]+slice[j], slice[j]+slice[i]
        return ij > ji
    })

    if slice[0] == "0" {
        return "0"
    }
    for i := 0; i < size; i++ {
        ans += slice[i]
    }

    return ans
}
