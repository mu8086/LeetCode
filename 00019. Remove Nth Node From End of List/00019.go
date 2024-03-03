// https://leetcode.com/problems/remove-nth-node-from-end-of-list

func removeNthFromEnd(head *ListNode, n int) *ListNode {
    var prev *ListNode = nil
    var fast *ListNode = head

    for i := 0; i < n; i++ {
        fast = fast.Next
    }

    if fast == nil {
        return head.Next
    }

    // 1 step for init prev to head
    prev, fast = head, fast.Next

    for fast != nil {
        prev = prev.Next
        fast = fast.Next
    }

    prev.Next = prev.Next.Next
    return head
}
