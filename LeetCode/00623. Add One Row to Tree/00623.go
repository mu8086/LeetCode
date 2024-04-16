// https://leetcode.com/problems/add-one-row-to-tree

func addOneRow(root *TreeNode, val int, depth int) *TreeNode {
    if depth > 1 {
        if root == nil {
            return nil
        }

        root.Left = addOneRow(root.Left, val, depth-1)        
        root.Right = addOneRow(root.Right, val, depth-1)

        if depth == 2 {
            if root.Right != nil {
                root.Right.Right = root.Right.Left
                root.Right.Left = nil
            }
        }

        return root
    }

    node := &TreeNode{
        Val: val,
        Left: root,
    }

    return node
}
