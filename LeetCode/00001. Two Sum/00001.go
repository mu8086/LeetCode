// https://leetcode.com/problems/two-sum

var idx []int

type slice []int

func (s slice) Len() int {
	return len(s)
}

func (s slice) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
    idx[i], idx[j] = idx[j], idx[i]
}

func (s slice) Less(i, j int) bool {
	return s[i] < s[j]
}

func twoSum(nums []int, target int) []int {
    idx = make([]int, len(nums), len(nums))
    for i := range nums {
        idx[i] = i
    }

    sort.Sort(slice(nums))
    
    l, r := 0, len(nums)-1
    for a, b := nums[l], nums[r]; ; {
        sum := a + b
        if sum == target {
            break
        } else if sum < target {
            l++
            a = nums[l]
        } else {
            r--
            b = nums[r]
        }
    }
    
    return []int{idx[l], idx[r]}
}
