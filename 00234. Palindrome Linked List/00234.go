// https://leetcode.com/problems/palindrome-linked-list

func isPalindrome(head *ListNode) bool {
    var second *ListNode
    slow, fast := head, head.Next
    stack := []*ListNode{slow}

    for fast != nil && fast.Next != nil {
        fast = fast.Next.Next
        slow = slow.Next
        stack = append(stack, slow)
    }
    // slow will be first part end

    if fast != nil {    // even node size
        second = slow.Next
    } else {            // odd node size
        second = slow
    }

    for i := len(stack)-1; i >= 0; i-- {
        if stack[i].Val != second.Val {
            return false
        }
        second = second.Next
    }

    return true
}
