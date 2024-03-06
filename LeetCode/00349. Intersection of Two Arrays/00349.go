// https://leetcode.com/problems/intersection-of-two-arrays

func intersection(nums1 []int, nums2 []int) (ans []int) {
    m := make(map[int]bool)

    for i := 0; i < len(nums1); i++ {
        m[nums1[i]] = true
    }

    for i := 0; i < len(nums2); i++ {
        if m[nums2[i]] == true {
            ans = append(ans, nums2[i])
            m[nums2[i]] = false // prevent duplicate
        }
    }

    return ans
}
