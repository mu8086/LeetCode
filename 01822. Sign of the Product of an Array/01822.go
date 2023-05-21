// https://leetcode.com/problems/sign-of-the-product-of-an-array

func arraySign(nums []int) int {
    sign := 1

    for _, v := range nums {
        if v == 0 {
            return 0
        } else if v < 1 {
            sign *= -1
        }
    }

    return sign
}
