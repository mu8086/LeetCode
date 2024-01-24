// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree

func pseudoPalindromicPaths (root *TreeNode) int {
    return dfs(root, 0)
}

func dfs(node *TreeNode, bitmap int) (path int) {
    if node == nil {
        return 0
    }

    bitmap ^= (1 << node.Val)

    if node.Left == nil && node.Right == nil {
        // odd frequency in the bitmap, must be 0 or 1 count to form a Pseudo-Palindromic Paths
        if bitmap & (bitmap-1) == 0 {
            return 1
        }
        return 0
    }

    return dfs(node.Left, bitmap) + dfs(node.Right, bitmap)
}
