// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

func lowestCommonAncestorV1(root, p, q *TreeNode) *TreeNode {
    var dfs func(node *TreeNode) (bool, bool, *TreeNode)
    dfs = func(node *TreeNode) (foundP, foundQ bool, ancestor *TreeNode) {
        if node == nil {
            return false, false, nil
        }

        lP, lQ, l := dfs(node.Left)
        if lP && lQ {
            return true, true, l
        }

        rP, rQ, r := dfs(node.Right)
        if rP && rQ {
            return true, true, r
        }

        if node == p {
            return true, lQ || rQ, node
        } else if node == q {
            return lP || rP, true, node
        }
        return lP || rP, lQ || rQ, node
    }

    _, _, ancestor := dfs(root)
    return ancestor
}

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    if root == nil || root == p || root == q {
        return root
    }

    l := lowestCommonAncestor(root.Left, p, q)
    r := lowestCommonAncestor(root.Right, p, q)

    if l != nil && r != nil {
        return root
    } else if l != nil {
        return l
    }
    return r
}
