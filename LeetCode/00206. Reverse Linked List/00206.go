// https://leetcode.com/problems/reverse-linked-list

func reverseList(head *ListNode) *ListNode {
    dummy := ListNode{}

    for head != nil {
        curr := head
        head = head.Next
        curr.Next = dummy.Next
        dummy.Next = curr
    }

    return dummy.Next
}
