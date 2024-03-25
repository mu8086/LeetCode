// https://leetcode.com/problems/find-all-duplicates-in-an-array

func findDuplicates(nums []int) []int {
    m := make(map[int]int)
    for _, num := range nums {
        m[num]++
    }

    ans := make([]int, 0, 0)
    for num, freq := range m {
        if freq > 1 {
            ans = append(ans, num)
        }
    }

    return ans
}
