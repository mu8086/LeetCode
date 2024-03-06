// https://leetcode.com/problems/subsets-ii

func subsetsWithDup(nums []int) [][]int {
    ans := [][]int{[]int{}}

    m := make(map[int]int)
    for _, num := range nums {
        m[num]++
    }

    for val, freq := range m {
        ansSize := len(ans)
        for i := 0; i < ansSize; i++ {
            sliceSize := len(ans[i])
            tmp := make([]int, sliceSize, sliceSize)
            copy(tmp, ans[i])
            for j := 0; j < freq; j++ {
                tmp = append(tmp, val)
                ans = append(ans, tmp)
            }
        }
    }

    return ans
}
