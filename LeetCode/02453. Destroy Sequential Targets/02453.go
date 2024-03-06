// https://leetcode.com/problems/destroy-sequential-targets

func destroyTargets(nums []int, space int) int {
    // key     : nums[i] % space
    // value[0]: freq
    // value[1]: minimum member
    m := make(map[int][2]int)

    maxFreq := 0
    for i := len(nums)-1; i >= 0; i-- {
        val := nums[i] % space
        
        arr := m[val]
        arr[0]++
        if maxFreq < arr[0] {
            maxFreq = arr[0]
        }

        if arr[1] == 0 || arr[1] > nums[i] {
            arr[1] = nums[i]
        }

        m[val] = arr
    }

    ans := 1000000001
    for _, arr := range m {
        if arr[0] == maxFreq && ans > arr[1] {
            ans = arr[1]
        }
    }

    return ans
}
