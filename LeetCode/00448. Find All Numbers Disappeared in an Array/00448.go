// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

func findDisappearedNumbers(nums []int) (ans []int) {
    m := make(map[int]bool)

    for _, v := range nums {
        m[v] = true
    }

    for i := 1; i <= len(nums); i++ {
        if !m[i] {
            ans = append(ans, i)
        }
    }

    return ans
}
