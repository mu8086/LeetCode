// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list

func doubleIt(head *ListNode) *ListNode {
    stack := []*ListNode{}

    for node := head; node != nil; node = node.Next {
        stack = append(stack, node)
    }

    carry := 0
    for i := len(stack)-1; i > 0; i-- {
        v := stack[i].Val*2 + carry

        if v > 9 {
            v -= 10
            carry = 1
        } else {
            carry = 0
        }

        stack[i].Val = v
    }

    head.Val = head.Val*2 + carry
    if head.Val > 9 {
        head.Val -= 10
        head = &ListNode{
            Val: 1,
            Next: head,
        }
    }

    return head
}
