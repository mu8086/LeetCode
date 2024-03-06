// https://leetcode.com/problems/summary-ranges

func summaryRanges(nums []int) (ans []string) {
    if len(nums) == 0 {
        return
    }

    for i, lastIdx := 0, len(nums)-1; i <= lastIdx; i++ {
        l := i
        for j := i+1; j <= lastIdx; j++ {
            if nums[j-1]+1 != nums[j] {
                break
            }

            i = j
        }
        if l == i {
            ans = append(ans, fmt.Sprintf("%d", nums[l]))
        } else {
            ans = append(ans, fmt.Sprintf("%d->%d", nums[l], nums[i]))
        }
    }

    return ans
}
