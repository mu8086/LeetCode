// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }

    dummy := &ListNode{ Val: -101, Next: head }

    for prev, node := dummy, head; node.Next != nil; {
        if v := node.Val; v == node.Next.Val {
            // found duplicate node, loop through next distinct number (non-duplicate node candidate)
            for node = node.Next.Next; node != nil; node = node.Next {
                if v != node.Val {
                    break
                }
            }

            prev.Next = node

            if node == nil {
                break
            }
        } else {
            prev = node
            node = node.Next
        }
    }

    return dummy.Next
}
