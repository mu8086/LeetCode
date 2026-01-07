// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxProduct(root *TreeNode) int {
    sumList := make([]int, 0)

    var dfs func(node *TreeNode) int
    dfs = func(node *TreeNode) int {
        if node == nil {
            return 0
        }

        sum := node.Val
        if node.Left != nil {
            sum += dfs(node.Left)
        }
        if node.Right != nil {
            sum += dfs(node.Right)
        }

        sumList = append(sumList, sum)
        return sum
    }

    sum := dfs(root)

    var ans int
    for _, subSum := range sumList {
        ans = max(ans, (sum-subSum) * subSum)
    }

    return ans % 1000000007
}
