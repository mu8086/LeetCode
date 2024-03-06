// https://leetcode.com/problems/build-an-array-with-stack-operations

func buildArray(target []int, n int) (ans []string) {
    for walker, targetIdx, targetLen := 1, 0, len(target); walker <= n; walker++ {
        if walker == target[targetIdx] {
            ans = append(ans, "Push")

            targetIdx++
            if targetIdx == targetLen {
                break
            }
        } else {
            ans = append(ans, "Push", "Pop")
        }
    }

    return ans
}
