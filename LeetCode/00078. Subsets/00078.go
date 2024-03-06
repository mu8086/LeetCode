// https://leetcode.com/problems/subsets

func subsets(nums []int) (ans [][]int) {
    ans = append(ans, []int{})

    for _, num := range nums {
        for idx := range ans {
            tmp := make([]int, len(ans[idx]))
            copy(tmp, ans[idx])

            tmp = append(tmp, num)

            ans = append(ans, tmp)
        }
    }

    return ans
}
