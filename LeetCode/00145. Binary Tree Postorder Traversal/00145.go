// https://leetcode.com/problems/binary-tree-postorder-traversal

func postorder(root *TreeNode, order *[]int) {
    if root == nil {
        return
    }

    postorder(root.Left, order)
    postorder(root.Right, order)
    *order = append(*order, root.Val)
}

func postorderTraversal(root *TreeNode) (order []int) {
    postorder(root, &order)
    return order
}
