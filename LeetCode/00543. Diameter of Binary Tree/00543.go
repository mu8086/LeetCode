// https://leetcode.com/problems/diameter-of-binary-tree

func helper(root *TreeNode, ans *int) int {
    if root == nil {
        return 0
    }

    l := helper(root.Left, ans)
    r := helper(root.Right, ans)
    if *ans < l+r {
        *ans = l+r
    }

    return max(l, r) + 1
}

func diameterOfBinaryTree(root *TreeNode) int {
    ans := 0
    helper(root, &ans)
    return ans
}
