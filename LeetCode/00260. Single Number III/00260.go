// https://leetcode.com/problems/single-number-iii

func singleNumber(nums []int) (ans []int) {
    sort.Ints(nums)

    size := len(nums)
    for i := 1; i < size; {
        if nums[i-1] != nums[i] {
            ans = append(ans, nums[i-1])
            if len(ans) == 2 {
                break
            }

            i += 1
        } else {
            i += 2
        }
    }

    if len(ans) != 2 {
        ans = append(ans, nums[size-1])
    }

    return ans
}
