// https://leetcode.com/problems/find-the-difference-of-two-arrays

// map & bitwise
func findDifference(nums1 []int, nums2 []int) [][]int {
    m := make(map[int]int)
    ans := make([][]int, 2)

    for i := len(nums1)-1; i >= 0; i-- {
        m[nums1[i]] |= 1
    }

    for i := len(nums2)-1; i >= 0; i-- {
        m[nums2[i]] |= 2
    }

    for k, v := range m {
        if v < 3 {
            ans[v-1] = append(ans[v-1], k)
        }
    }

    return ans
}

// sort
func findDifferenceSort(nums1 []int, nums2 []int) [][]int {
    ans := make([][]int, 2)
    size1, size2 := len(nums1), len(nums2)

    sort.Ints(nums1)
    sort.Ints(nums2)

    newIdx := func(slice []int, idx, size int) int {
        for idx++; idx < size; idx++ {
            if slice[idx-1] != slice[idx] {
                break
            }
        }
        return idx
    }

    i1, i2 := 0, 0
    for i1 < size1 && i2 < size2 {
        if nums1[i1] == nums2[i2] {
            i1 = newIdx(nums1, i1, size1)
            i2 = newIdx(nums2, i2, size2)
        } else if nums1[i1] < nums2[i2] {
            ans[0] = append(ans[0], nums1[i1])
            i1 = newIdx(nums1, i1, size1)
        } else {
            ans[1] = append(ans[1], nums2[i2])
            i2 = newIdx(nums2, i2, size2)
        }
    }

    for i1 < size1 {
        ans[0] = append(ans[0], nums1[i1])
        i1 = newIdx(nums1, i1, size1)
    }

    for i2 < size2 {
        ans[1] = append(ans[1], nums2[i2])
        i2 = newIdx(nums2, i2, size2)
    }

    return ans
}
