// https://leetcode.com/problems/merge-in-between-linked-lists

func mergeInBetween(list1 *ListNode, a int, b int, list2 *ListNode) *ListNode {
    prevA := list1
    for i := 1; i < a; i++ {
        prevA = prevA.Next
    }

    nodeB := prevA
    for i := b-a+2; i > 0; i-- {
        nodeB = nodeB.Next
    }

    prevA.Next = list2
    for list2.Next != nil {
        list2 = list2.Next
    }
    list2.Next = nodeB

    return list1
}
