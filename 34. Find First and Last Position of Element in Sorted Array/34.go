import (
    "sort"
)

func searchRange(nums []int, target int) []int {
    ret := []int{-1, -1}
    
    tmp := sort.Search(len(nums), func(i int) bool { return nums[i] >= target } )
    if tmp == len(nums) || nums[tmp] != target {
        // not found
        return ret
    } else {
        ret[0] = tmp
    }
    
    tmp = sort.Search(len(nums), func(i int) bool { return nums[i] > target })
    ret[1] = tmp-1

    return ret;
}
