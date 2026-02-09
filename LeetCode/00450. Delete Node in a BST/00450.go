// https://leetcode.com/problems/delete-node-in-a-bst

func deleteNode(root *TreeNode, key int) *TreeNode {
    if root == nil {
        return nil
    } else if root.Val < key {
        root.Right = deleteNode(root.Right, key)
    } else if root.Val > key {
        root.Left = deleteNode(root.Left, key)
    } else {
        if root.Right == nil {
            return root.Left
        } else if root.Left == nil {
            return root.Right
        }

        root.Val = findMin(root.Right)
        root.Right = deleteNode(root.Right, root.Val)
    }

    return root
}

func findMin(node *TreeNode) int {
    for node.Left != nil {
        node = node.Left
    }
    return node.Val
}
