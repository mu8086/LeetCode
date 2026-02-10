// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree

func longestZigZag(root *TreeNode) int {
    const (
        LEFT = iota
        RIGHT
    )

    ans := 0

    var dfs func(node *TreeNode, goLeft bool, level int)
    dfs = func(node *TreeNode, goLeft bool, level int) {
        if node == nil {
            if ans < level {
                ans = level
            }
            return
        }

        if goLeft {
            dfs(node.Left, false, level+1)
            dfs(node.Right, true, 0)
        } else {
            dfs(node.Left, false, 0)
            dfs(node.Right, true, level+1)
        }
    }

    dfs(root.Left, false, 0)
    dfs(root.Right, true, 0)

    return ans
}
