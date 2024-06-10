// https://leetcode.com/problems/height-checker

func heightChecker(heights []int) int {
    size := len(heights)
    sorted := make([]int, size, size)
    
    copy(sorted, heights)
    sort.Ints(sorted)

    ans := 0
    for idx := range sorted {
        if sorted[idx] != heights[idx] {
            ans++
        }
    }

    return ans
}
