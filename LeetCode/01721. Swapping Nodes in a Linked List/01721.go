// https://leetcode.com/problems/swapping-nodes-in-a-linked-list

func swapNodes(head *ListNode, k int) *ListNode {
    a, b := head, head

    for i := 1; i < k; i++ {
        a = a.Next
    }
    
    for tmp := a.Next; tmp != nil; tmp = tmp.Next {
        b = b.Next
    }
    
    a.Val, b.Val = b.Val, a.Val
    
    return head
}
