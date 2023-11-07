// https://leetcode.com/problems/subsets

func subsets(nums []int) (ans [][]int) {
    ans = append(ans, []int{})

    for i, lenNums := 0, len(nums); i < lenNums; i++ {
        for j, lenAns := 0, len(ans); j < lenAns; j++ {
            lenAnsJ := len(ans[j])
            tmp := make([]int, lenAnsJ+1)
            copy(tmp, ans[j])

            tmp[lenAnsJ] = nums[i]

            ans = append(ans, tmp)
        }
    }

    return ans
}
