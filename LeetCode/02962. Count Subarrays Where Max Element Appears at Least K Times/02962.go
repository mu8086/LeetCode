// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times

func countSubarrays(nums []int, k int) (ans int64) {
    maxVal, size := 0, len(nums)
    maxValIdx := make([]int, 0, 0)

    for i := 0; i < size; i++ {
        if maxVal < nums[i] {
            maxVal = nums[i]
            maxValIdx = []int{i}
        } else if maxVal == nums[i] {
            maxValIdx = append(maxValIdx, i)
        }
    }

    maxValIdxSize := len(maxValIdx)
    if maxValIdxSize < k {
        return 0
    }

    idxOfFirstRequiredIdx, idxOfLastRequiredIdx := 0, k-1
    firstRequiredIdx := maxValIdx[idxOfFirstRequiredIdx]
    lastRequiredIdx := maxValIdx[idxOfLastRequiredIdx]

    nextIdx := func () (int, int) {
        idxOfFirstRequiredIdx++
        idxOfLastRequiredIdx++

        if idxOfLastRequiredIdx == maxValIdxSize {
            return -1, -1
        }
        return maxValIdx[idxOfFirstRequiredIdx], maxValIdx[idxOfLastRequiredIdx]
    }

    subarrayStartIdx := 0
    for round := maxValIdxSize-k; round >= 0; round-- {
        ans += int64((firstRequiredIdx-subarrayStartIdx+1) * (size-lastRequiredIdx))
        subarrayStartIdx = firstRequiredIdx+1

        firstRequiredIdx, lastRequiredIdx = nextIdx()
    }

    return ans
}
