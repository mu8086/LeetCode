// https://leetcode.com/problems/arithmetic-subarrays

func isArithmetic(nums []int, l, r, query int, m map[int]int) bool {
    size := r - l + 1
    if size <= 2 {
        return true
    }

    min, max := nums[l], nums[l]
    for i := l; i <= r; i++ {
        m[nums[i]] = query

        if min > nums[i] {
            min = nums[i]
        }
        if max < nums[i] {
            max = nums[i]
        }
    }

    if (max - min) % (size - 1) != 0 {
        return false
    }

    for tmp, diff := min, (max-min) / (size-1); size > 0; tmp, size = tmp+diff, size-1 {
        if val, exists := m[tmp]; !exists || val != query {
            return false
        }
    }

    return true
}

func checkArithmeticSubarrays(nums []int, l []int, r []int) []bool {
    size := len(l)
    ans := make([]bool, size, size)
    m := make(map[int]int)  // key: nums[i], value: lastest occurrence in l[i] ~ r[i]

    for i := 0; i < size; i++ {
        ans[i] = isArithmetic(nums, l[i], r[i], i, m)
    }

    return ans
}
