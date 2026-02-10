// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

func pairSum(head *ListNode) int {
    slow, fast := head, head
    for fast != nil && fast.Next != nil {
        prev := slow

        slow = slow.Next
        fast = fast.Next.Next

        prev.Next = head
        head = prev
    }

    maxSum := 0
    for slow != nil {
        maxSum = max(maxSum, head.Val + slow.Val)
        head, slow = head.Next, slow.Next
    }

    return maxSum
}
