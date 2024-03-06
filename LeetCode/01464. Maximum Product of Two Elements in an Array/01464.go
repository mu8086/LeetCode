// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array

func maxProduct(nums []int) int {
    sort.Ints(nums)
    return (nums[len(nums)-1] - 1) * (nums[len(nums)-2] - 1)
}

func maxProduct2(nums []int) int {
    maximum, prevMax := max(nums[0], nums[1]), min(nums[0], nums[1])

    for i := len(nums)-1; i >= 2; i-- {
        if nums[i] > prevMax {
            if nums[i] >= maximum {
                maximum, prevMax = nums[i], maximum
            } else {
                prevMax = nums[i]
            }
        }
    }

    return (maximum-1) * (prevMax-1)
}
