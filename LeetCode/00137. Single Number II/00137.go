// https://leetcode.com/problems/single-number-ii

func singleNumber(nums []int) int {
    return singleNumberSort(nums)
}

// sort
func singleNumberSort(nums []int) int {
    sort.Ints(nums)

    l := len(nums)-1
    if l == 0 || nums[0] != nums[1] {
        return nums[0]
    }

    for i := 3; i < l; i += 3 {
        if nums[i] != nums[i+1] {
            return nums[i]
        }
    }

    return nums[l]
}

// map
func singleNumberMap(nums []int) int {
    m := make(map[int]int)

    for _, num := range nums{
        m[num]++
    }

    for k, v := range m {
        if v == 1 {
            return k
        }
    }

    return -1
}

// bit version 1 (others' submission)
func singleNumberBit1(nums []int) int {
    one, two := 0, 0
    for _, n := range nums {
        two |= n & one
        one ^= n
        t := one & two
        one &= ^t
        two &= ^t
    }
    return one
}

// bit version 2 (others' submission)
func singleNumberBit2(nums []int) int {
    // Initialize seenOnce and seenTwice to 0
    seenOnce, seenTwice := 0, 0

    // Iterate through nums
    for _, num := range nums {
        // Update using derived equations
        seenOnce = (seenOnce ^ num) & (^seenTwice)
        seenTwice = (seenTwice ^ num) & (^seenOnce)
    }

    // Return integer which appears exactly once
    return seenOnce
}
