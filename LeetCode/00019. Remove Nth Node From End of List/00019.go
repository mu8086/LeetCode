// https://leetcode.com/problems/remove-nth-node-from-end-of-list

func removeNthFromEnd(head *ListNode, n int) *ListNode {
    dummy := &ListNode{ Next: head }

    slow, fast := dummy, dummy
    for n > 0 {
        fast = fast.Next
        n--
    }

    for fast.Next != nil {
        slow, fast = slow.Next, fast.Next
    }
    slow.Next = slow.Next.Next
    
    return dummy.Next
}
