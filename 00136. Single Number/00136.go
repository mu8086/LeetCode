// https://leetcode.com/problems/single-number

// best solution
func singleNumber(nums []int) int {
    ans := nums[0]
    for i := 1; i < len(nums); i++ {
        ans ^= nums[i]
    }
    return ans
}

// trivial solution
func _singleNumber(nums []int) (ans int) {
    m := make(map[int]bool)

    for _, n := range nums {
        if _, exist := m[n]; exist {
            delete(m, n)
        } else {
            m[n] = true
        }
    }

    for k := range m {
        ans = k
        break
    }

    return ans
}
