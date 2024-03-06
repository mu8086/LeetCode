// https://leetcode.com/problems/find-unique-binary-string

// others' submission
func findDifferentBinaryString(nums []string) (ans string) {
    for i, size := 0, len(nums); i < size; i++ {
        if nums[i][i] == '0' {
            ans += "1"
        } else {
            ans += "0"
        }
    }

    return ans
}

func findDifferentBinaryStringVer0(nums []string) string {
    sort.Strings(nums)

    var (
        i int
        size = len(nums)
    )

    for i = 0; i < size; i++ {
        num, _ := strconv.ParseInt(nums[i], 2, 32)
        if num != int64(i) {
            break
        }
    }

    s := strconv.FormatInt(int64(i), 2)
    for zero := len(nums[0])-len(s); zero > 0; zero-- {
        s = "0" + s
    }
    return s
}
