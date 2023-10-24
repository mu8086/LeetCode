// https://leetcode.com/problems/search-insert-position

func searchInsert(nums []int, target int) (idx int) {
    for l, r := 0, len(nums)-1; l < r; {
        idx = l + (r-l)/2

        if nums[idx] == target {
            return idx
        } else if nums[idx] < target {
            l = idx+1
        } else {
            r = idx
        }
    }

    if nums[idx] < target {
        idx++
    }

    return idx
}
