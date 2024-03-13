// https://leetcode.com/problems/find-the-pivot-integer

func pivotInteger(n int) int {
    prefixSum, suffixSum := ((1+n) * n) >> 1, 0

    for pivot := n; pivot > 0; pivot-- {
        suffixSum += pivot

        if prefixSum == suffixSum {
            return pivot
        }

        prefixSum -= pivot
    }

    return -1
}
