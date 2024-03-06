// https://leetcode.com/problems/find-bottom-left-tree-value

func helper(root *TreeNode, depth int, deepestLevel, ans *int) {
    if root == nil {
        return
    }

    helper(root.Left, depth+1, deepestLevel, ans)
    helper(root.Right, depth+1, deepestLevel, ans)

    if *deepestLevel < depth {
        *deepestLevel = depth
        *ans = root.Val
    }
}

func findBottomLeftValue(root *TreeNode) int {
    ans := root.Val
    deepestLevel := 0
    helper(root, 0, &deepestLevel, &ans)
    return ans
}
