// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor

func helper(node *TreeNode, minVal, maxVal int, ans *int) {
    if node == nil {
        return
    }

    if maxVal < node.Val {
        maxVal = node.Val
        if diff := maxVal - minVal; diff > *ans {
            *ans = diff
        }
    } else if minVal > node.Val {
        minVal = node.Val
        if diff := maxVal - minVal; diff > *ans {
            *ans = diff
        }
    }

    helper(node.Left, minVal, maxVal, ans)
    helper(node.Right, minVal, maxVal, ans)
}

func maxAncestorDiff(root *TreeNode) (ans int) {
    helper(root, root.Val, root.Val, &ans)
    return ans
}
