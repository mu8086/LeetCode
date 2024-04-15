// https://leetcode.com/problems/sum-root-to-leaf-numbers

func helper(root *TreeNode, prefix int) int {
    if root == nil {
        return 0
    }

    prefix = prefix * 10 + root.Val

    if root.Left == nil && root.Right == nil {
        return prefix
    }
    return helper(root.Left, prefix) + helper(root.Right, prefix)
}

func sumNumbers(root *TreeNode) int {
    return helper(root, 0)
}
