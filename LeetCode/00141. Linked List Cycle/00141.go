// https://leetcode.com/problems/linked-list-cycle

// formal solution
func hasCycle(head *ListNode) bool {
    if head == nil || head.Next == nil {
        return false
    }

    for slow, fast := head, head.Next; slow != fast; slow = slow.Next {
        if fast.Next == nil || fast.Next.Next == nil {
            return false
        }
        fast = fast.Next.Next
    }

    return true
}

// trivial solution (only for easy question)
func _hasCycle(head *ListNode) bool {
    for i := 0; head != nil; head = head.Next {
        if i >= 10000 {
            return true
        }
        i++
    }

    return false
}
