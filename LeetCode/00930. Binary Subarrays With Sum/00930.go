// https://leetcode.com/problems/binary-subarrays-with-sum

func numSubarraysWithSum(nums []int, goal int) int {
    ans, size := 0, len(nums)
    sumMap := make(map[int]int)

    sumMap[0] = 1
    for i, sum := 0, 0; i < size; i++ {
        sum += nums[i]

        if freq := sumMap[sum-goal]; freq != 0 {
            ans += freq
        }

        sumMap[sum]++
    }

    return ans
}
