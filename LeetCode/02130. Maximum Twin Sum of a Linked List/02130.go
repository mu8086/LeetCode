// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

func listToIntSlice(head *ListNode) (slice []int) {
    for ; head != nil; head = head.Next {
        slice = append(slice, head.Val)
    }

    return slice
}

func pairSum(head *ListNode) int {
    slice := listToIntSlice(head)
    
    lastIdx := len(slice)-1
    max := slice[0] + slice[lastIdx]
    for i := len(slice)/2-1; i > 0; i-- {
        sum := slice[i] + slice[lastIdx-i]
        if max < sum {
            max = sum
        }
    }

    return max
}
