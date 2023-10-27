// https://leetcode.com/problems/binary-tree-paths

func dfs(root *TreeNode, prefix string, ans *[]string) {
    if root == nil {
        return
    }

    prefix += fmt.Sprintf("%v->", root.Val)

    if root.Left == nil && root.Right == nil {
        *ans = append(*ans, prefix[:len(prefix)-2])
        return
    }

    dfs(root.Left, prefix, ans)
    dfs(root.Right, prefix, ans)
}

func binaryTreePaths(root *TreeNode) (ans []string) {
    dfs(root, "", &ans)
    return ans
}
