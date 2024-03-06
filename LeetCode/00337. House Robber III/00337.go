// https://leetcode.com/problems/house-robber-iii

// others submission
func rob(root *TreeNode) int {
    var dfs func(*TreeNode) (int, int)
    dfs = func(root *TreeNode) (int, int) {
        if root == nil {
            return 0, 0
        }

        lWith, lWithout := dfs(root.Left)
        rWith, rWithout := dfs(root.Right)

        return root.Val + lWithout + rWithout, max(lWith, lWithout) + max(rWith, rWithout)
    }

    withRoot, withoutRoot := dfs(root)
    return max(withRoot, withoutRoot)
}

// cached visited node
func robBad(root *TreeNode) int {
    robM := make(map[*TreeNode]int)
    notM := make(map[*TreeNode]int)

    var dfs func(*TreeNode, bool, int) int
    dfs = func(root *TreeNode, parentRobbed bool, sum int) (ans int) {
        if root == nil {
            return sum
        }

        if !parentRobbed {
            rob, exists := robM[root]
            if !exists {
                rob = dfs(root.Left, true, sum) + dfs(root.Right, true, sum)
                robM[root] = rob
            }

            not, exists := notM[root]
            if !exists {
                not = dfs(root.Left, false, sum) + dfs(root.Right, false, sum)
                notM[root] = not
            }
            return max(rob+root.Val, not)
        } else {
            not, exists := notM[root]
            if !exists {
                not = dfs(root.Left, false, sum) + dfs(root.Right, false, sum)
                notM[root] = not
            }
            return not
        }
    }

    return dfs(root, false, 0)
}
