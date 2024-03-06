// https://leetcode.com/problems/range-sum-of-bst

func rangeSumBST(root *TreeNode, low int, high int) (sum int) {
    if root == nil {
        return 0
    }

    if root.Val >= low && root.Val <= high {
        sum = root.Val
    }

    return sum + rangeSumBST(root.Left, low, high) + rangeSumBST(root.Right, low, high)
}
