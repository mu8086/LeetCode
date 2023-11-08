// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

func sortedListToBST(head *ListNode) *TreeNode {
    if head == nil {
        return nil
    }

    var prev, slow, fast *ListNode = nil, head, head

    for fast != nil && fast.Next != nil {
        prev = slow
        slow = slow.Next
        fast = fast.Next.Next
    }
    if prev == nil {    // only one node
        return &TreeNode{
            Val: slow.Val,
        }
    } else {    // cut the link between left and root
        prev.Next = nil
    }

    return &TreeNode{
        Val: slow.Val,
        Left: sortedListToBST(head),
        Right: sortedListToBST(slow.Next),
    }
}
