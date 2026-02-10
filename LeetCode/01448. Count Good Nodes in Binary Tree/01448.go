// https://leetcode.com/problems/count-good-nodes-in-binary-tree

func goodNodes(root *TreeNode) int {
    var dfs func(*TreeNode, int) int
    dfs = func(node *TreeNode, maxVal int) int {
        if node == nil {
            return 0
        }

        count := 0
        if maxVal <= node.Val {
            maxVal = node.Val
            count++
        }

        return count + dfs(node.Left, maxVal) + dfs(node.Right, maxVal)
    }

    return dfs(root, root.Val)
}
