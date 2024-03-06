// https://leetcode.com/problems/rotate-array

func rotate(nums []int, k int) {
    size := len(nums)
    k %= size

    if k == 0 {
        return
    }

    slices.Reverse(nums)
    slices.Reverse(nums[:k])
    slices.Reverse(nums[k:])

    return
}

func rotate2(nums []int, k int) {
    size := len(nums)
    k %= size

    if k == 0 {
        return
    }

    gcdF := func(a, b int) int {
        if a < b {
            a, b = b, a
        }

        for b != 0 {
            a, b = b, a%b
        }

        return a
    }

    for i, gcd := 0, gcdF(k, size); i < gcd; i++ {
        tmp := nums[i]
        for j := i+k; j != i; j = (j+k)%size {
            tmp, nums[j] = nums[j], tmp
        }
        nums[i] = tmp
    }

    return
}
