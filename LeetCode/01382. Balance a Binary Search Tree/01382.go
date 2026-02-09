// https://leetcode.com/problems/balance-a-binary-search-tree

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func balanceBST(root *TreeNode) *TreeNode {
    list := make([]*TreeNode, 0)
    inorder(root, &list)
    return helper(list, 0, len(list)-1)
}

func inorder(root *TreeNode, listPtr *[]*TreeNode) {
    if root == nil || listPtr == nil {
        return
    }

    inorder(root.Left, listPtr)
    *listPtr = append(*listPtr, root)
    inorder(root.Right, listPtr)
}

func helper(list []*TreeNode, start, end int) *TreeNode {
    if start > end {
        return nil
    }

    mid := start + (end-start) >> 1

    node := list[mid]
    node.Left = helper(list, start, mid-1)
    node.Right = helper(list, mid+1, end)

    return node
}
