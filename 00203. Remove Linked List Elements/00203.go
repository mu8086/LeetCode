// https://leetcode.com/problems/remove-linked-list-elements

func removeElements(head *ListNode, val int) *ListNode {
    dummy := &ListNode{
        Next: head,
    }

    walker := dummy
    for ; head != nil; head = head.Next {
        if head.Val != val {
            walker.Next = head
            walker = walker.Next
        }
    }

    walker.Next = nil

    return dummy.Next
}

// another solution
func _removeElements(head *ListNode, val int) *ListNode {
    dummy := &ListNode{
        Next: head,
    }

    head = dummy
    for head != nil && head.Next != nil {
        if head.Next.Val == val {
            head.Next = head.Next.Next
        } else {
            head = head.Next
        }
    }

    return dummy.Next
}
