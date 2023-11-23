// https://leetcode.com/problems/arithmetic-subarrays

func checkArithmeticSubarrays(nums []int, l []int, r []int) []bool {
    isArithmetic := func(arr []int) bool {
        for i, diff := len(arr)-1, arr[1] - arr[0]; i > 0; i-- {
            if arr[i]-arr[i-1] != diff {
                return false
            }
        }
        return true
    }

    size := len(l)
    ans := make([]bool, size, size)
    for i := 0; i < size; i++ {
        subArr := make([]int, r[i]+1-l[i], r[i]+1-l[i])

        copy(subArr, nums[l[i]:r[i]+1])

        sort.Ints(subArr)

        ans[i] = isArithmetic(subArr)
    }

    return ans
}
