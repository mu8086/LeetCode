// https://leetcode.com/problems/reverse-linked-list

func reverseList(head *ListNode) (ans *ListNode) {
    if head == nil {
        return nil
    }

    for ans = head; head.Next != nil; {
        tmp := head.Next
        head.Next = head.Next.Next
        tmp.Next = ans
        ans = tmp
    }

    return ans
}
