// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list

func removeZeroSumSublists(head *ListNode) *ListNode {
    m := make(map[int]*ListNode)

    walker, prefixSum := head, 0
    for walker != nil {
        prefixSum += walker.Val
        m[prefixSum] = walker   // only hold the last node with same prefixSum

        walker = walker.Next
    }

    if m[0] != nil {
       head = m[0].Next
    }

    dummy := &ListNode{
        Val: 0,
        Next: head,
    }

    walker, prefixSum = dummy, 0
    for walker != nil {
        prefixSum += walker.Val

        if sameSum := m[prefixSum]; sameSum != nil && sameSum != walker {
            walker.Next = sameSum.Next
        }

        walker = walker.Next
    }

    return dummy.Next
}
