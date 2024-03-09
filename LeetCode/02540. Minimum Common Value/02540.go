// https://leetcode.com/problems/minimum-common-value

func getCommon(nums1 []int, nums2 []int) int {
    size1, size2 := len(nums1), len(nums2)

    idx1, idx2 := 0, 0
    for {
        if nums1[idx1] == nums2[idx2] {
            return nums1[idx1]
        } else if nums1[idx1] < nums2[idx2] {
            idx1++
            if idx1 >= size1 {
                break
            }
        } else {
            idx2++
            if idx2 >= size2 {
                break
            }
        }
    }

    return -1
}
