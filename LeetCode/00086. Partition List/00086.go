// https://leetcode.com/problems/partition-list

func partition(head *ListNode, x int) *ListNode {
    dummyA, dummyB := &ListNode{}, &ListNode{}
    a, b := dummyA, dummyB

    for head != nil {
        node := head
        head = head.Next
        node.Next = nil

        if node.Val < x {
            a.Next = node
            a = node
        } else {
            b.Next = node
            b = node
        }
    }
    a.Next = dummyB.Next

    return dummyA.Next
}
