// https://leetcode.com/problems/subsets

func subsets(nums []int) [][]int {
    ans := [][]int{[]int{}}

    for i, lenNums := 0, len(nums); i < lenNums; i++ {
        for j, lenAns := 0, len(ans); j < lenAns; j++ {
            tmp := make([]int, len(ans[j]))
            copy(tmp, ans[j])

            tmp = append(tmp, nums[i])

            ans = append(ans, tmp)
        }
    }

    return ans
}
