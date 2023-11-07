// https://leetcode.com/problems/linked-list-cycle-ii

func detectCycle(head *ListNode) *ListNode {
    m := map[*ListNode]struct{}{}

    for head != nil {
        if _, exists := m[head]; !exists {
            m[head] = struct{}{}
        } else {
            return head
        }

        head = head.Next
    }

    return nil
}
