// https://leetcode.com/problems/jump-game

func canJump(nums []int) bool {
    var lastIdx = len(nums)-1
    var reach = 0

    for i := 0; i<lastIdx && reach >= i; i++ {
        if reach >= lastIdx {
            return true
        } else if reach < i + nums[i] {
            reach = i + nums[i]
        }
    }

    return reach >= lastIdx
}
