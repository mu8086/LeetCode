// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func dfs(node *TreeNode, depth int) (*TreeNode, int) {
    if node == nil {
        return nil, depth-1
    }

    l, lDepth := dfs(node.Left, depth+1)
    r, rDepth := dfs(node.Right, depth+1)

    if lDepth > rDepth {
        return l, lDepth
    } else if lDepth < rDepth {
        return r, rDepth
    }
    return node, rDepth
}

func subtreeWithAllDeepest(root *TreeNode) *TreeNode {
    subtree, _ := dfs(root, 1)
    return subtree
}
