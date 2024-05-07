// https://leetcode.com/problems/delete-node-in-a-linked-list

func deleteNode(node *ListNode) {
    *node = *node.Next
}
