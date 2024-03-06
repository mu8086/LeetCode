// https://leetcode.com/problems/jump-game-ii

func jump(nums []int) (step int) {
    var i, l, reach, max, gap int

    for i, l = 0, len(nums)-1; i < l; i++ {
        reach = nums[i] + i
        if max < reach {
            max = reach
        }

        if i == gap {
            gap = max
            step++
        }
    }

    return step
}
