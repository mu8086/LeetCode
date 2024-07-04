// https://leetcode.com/problems/merge-nodes-in-between-zeros

func mergeNodes(head *ListNode) *ListNode {
    last := &ListNode{}

    for prev, cur := head, head.Next; cur != nil; cur = cur.Next {
        if cur.Val != 0 {
            prev.Val += cur.Val
        } else {
            last = prev
            prev.Next = cur
            prev = cur
        }
    }

    last.Next = nil
    return head
}
