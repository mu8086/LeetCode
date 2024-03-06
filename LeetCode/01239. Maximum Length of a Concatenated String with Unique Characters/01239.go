// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters

func maxLength(arr []string) int {
    arrSize := len(arr)

    strSize := make([]int, 0, 0)
    bitsArr := make([]int, 0, 0)

    InitLoop:
    for i := 0; i < arrSize; i++ {
        bits := 0
        for _, c := range arr[i] {
            offset := int(c-'a')
            if (bits >> offset) & 1 == 1 {    // dup in same string, skip it
                continue InitLoop
            }
            bits |= (1 << offset)
        }
        bitsArr = append(bitsArr, bits)
        strSize = append(strSize, len(arr[i]))
    }
    arrSize = len(bitsArr)

    noDup := func(a, b int) bool { return (a^b) == (a|b) }

    var dfs func(int, int) int
    dfs = func(bitmap, idx int) int {
        if idx == arrSize {
            return 0
        }

        pick, not := 0, 0
        if noDup(bitmap, bitsArr[idx]) {
            pick = strSize[idx] + dfs(bitmap|bitsArr[idx], idx+1)
        }
        not = dfs(bitmap, idx+1)

        return max(pick, not)
    }

    maxLen := 0
    for i := 0; i < arrSize; i++ {
        length := strSize[i] + dfs(bitsArr[i], i+1)
        if maxLen < length {
            maxLen = length
        }
    }

    return maxLen
}
