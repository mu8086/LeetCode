// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits

func numOf1Bits(n int) (ans int) {
    for n > 0 {
        ans += (n & 1)
        n >>= 1
    }
    return ans
}

func sortByBits(arr []int) []int {
    less := func (i, j int) bool {
        iBits, jBits := numOf1Bits(arr[i]), numOf1Bits(arr[j])
        if iBits != jBits {
            return iBits < jBits
        }
        return arr[i] < arr[j]
    }

    sort.Slice(arr, less)

    return arr
}
