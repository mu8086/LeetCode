// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty

func minOperations(nums []int) (ans int) {
    m := make(map[int]int)  // key: num, value: freq

    for _, num := range nums {
        m[num]++
    }

    for _, freq := range m {
        if freq == 1 {
            return -1
        }

        if freq % 3 == 0 {
            ans += freq / 3
        } else {
            ans += freq / 3 + 1
        }
    }

    return ans
}
