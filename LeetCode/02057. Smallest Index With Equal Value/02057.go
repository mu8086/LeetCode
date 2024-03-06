// https://leetcode.com/problems/smallest-index-with-equal-value/submissions/

func smallestEqual(nums []int) int {
    for i, n := range nums {
        if (i % 10) == n {
            return i
        }
    }

    return -1
}
