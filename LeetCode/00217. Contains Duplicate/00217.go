// https://leetcode.com/problems/contains-duplicate

// Time Optimization
func containsDuplicate(nums []int) bool {
    m := make(map[int]bool)

    for _, n := range nums {
        if m[n] == true {
            return true
        }

        m[n] = true
    }

    return false
}

// Space Optimization
func _containsDuplicate(nums []int) bool {
    sort.Ints(nums)

    for i := 1; i < len(nums); i++ {
        if nums[i-1] == nums[i] {
            return true
        }
    }

    return false
}
