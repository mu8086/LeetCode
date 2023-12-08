// https://leetcode.com/problems/delete-node-in-a-bst

func deleteNode(root *TreeNode, key int) *TreeNode {
    if root == nil {
        return nil
    }

    getReplaceNode := func(root *TreeNode) *TreeNode {
        node := root.Right
        for node != nil && node.Left != nil {
            node = node.Left
        }

        if node == nil {
            node = root.Left
            for node != nil && node.Right != nil {
                node = node.Right
            }
        }

        return node
    }

    if root.Val > key {
        root.Left = deleteNode(root.Left, key)
    } else if root.Val < key {
        root.Right = deleteNode(root.Right, key)
    } else {
        replaceNode := getReplaceNode(root)

        if replaceNode == nil {
            root = nil
        } else {
            tmp := replaceNode.Val
            root = deleteNode(root, tmp)
            root.Val = tmp
        }
    } 

    return root
}
