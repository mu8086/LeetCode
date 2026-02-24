// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers

func sumRootToLeaf(root *TreeNode) int {
    sum := 0

    var dfs func(node *TreeNode, carry int)
    dfs = func(node *TreeNode, carry int) {
        if node == nil {
            return
        }

        carry = (carry << 1) | node.Val
        if node.Left == nil && node.Right == nil {
            sum += carry
            return
        }

        dfs(node.Left, carry)
        dfs(node.Right, carry)
    }
    dfs(root, 0)

    return sum
}
