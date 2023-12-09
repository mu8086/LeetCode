// https://leetcode.com/problems/binary-tree-inorder-traversal

func inorderTraversal(root *TreeNode) []int {
    if root == nil {
        return nil
    }

    ans := append(inorderTraversal(root.Left), root.Val)
    ans = append(ans, inorderTraversal(root.Right)...)

    return ans
}
