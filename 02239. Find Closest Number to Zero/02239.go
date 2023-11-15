// https://leetcode.com/problems/find-closest-number-to-zero

func findClosestNumber(nums []int) int {
    distanceToZero := func (n int) int {
        if n < 0 {
            return -n
        }
        return n
    }

    n, d := nums[0], distanceToZero(nums[0])

    for i := len(nums)-1; i > 0; i-- {
        d2 := distanceToZero(nums[i])
        if d > d2 {
            n, d = nums[i], d2
        } else if d == d2 && n < nums[i] {
            n = nums[i]
        }
    }

    return n
}
