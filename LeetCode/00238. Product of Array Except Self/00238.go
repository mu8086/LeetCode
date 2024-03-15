// https://leetcode.com/problems/product-of-array-except-self

func productExceptSelf(nums []int) []int {
    size := len(nums)
    ans := make([]int, size, size)

    zero, zeroIdx, product := 0, 0, 1
    for i := 0; i < size; i++ {
        if nums[i] == 0 {
            zero, zeroIdx = zero+1, i
            if zero == 2 {
                break
            }

            continue
        }

        product *= nums[i]
    }

    if zero > 1 {
        return make([]int, size, size)
    } else if zero == 1 {
        ans = make([]int, size, size)
        ans[zeroIdx] = product
    } else {
        for i := 0; i < size; i++ {
            ans[i] = product / nums[i]
        }
    }

    return ans
}
