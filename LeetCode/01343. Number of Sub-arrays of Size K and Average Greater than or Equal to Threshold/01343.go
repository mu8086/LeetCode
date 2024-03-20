// https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold

func numOfSubarrays(arr []int, k int, threshold int) int {
    threshold *= k

    ans, size := 0, len(arr)
    for i := 1; i < size; i++ {
        arr[i] += arr[i-1]

        if i >= k && arr[i] - arr[i-k] >= threshold {
            ans++
        }
    }

    if arr[k-1] >= threshold {
        ans++
    }

    return ans
}
