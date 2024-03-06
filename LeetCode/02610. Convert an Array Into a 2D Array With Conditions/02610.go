// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions

func findMatrix(nums []int) [][]int {
    m := make(map[int]int)  // key: num, value: freq

    max := 0
    for _, num := range nums {
        m[num]++

        if max < m[num] {
            max = m[num]
        }
    }

    ans := make([][]int, max)
    for num, freq := range m {
        for i := 0; i < freq; i++ {
            ans[i] = append(ans[i], num)
        }
    }

    return ans
}
