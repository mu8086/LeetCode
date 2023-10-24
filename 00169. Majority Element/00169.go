// https://leetcode.com/problems/majority-element

// trivial solution
func majorityElement(nums []int) (majority int) {
    m := make(map[int]int)

    for _, n := range nums {
        m[n]++
    }

    target := len(nums)/2
    for k, v := range m {
        if v > target {
            majority = k
            break
        }
    }

    return majority 
}

// best solution: Boyer–Moore majority vote algorithm
