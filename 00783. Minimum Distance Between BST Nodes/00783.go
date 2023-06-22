// https://leetcode.com/problems/minimum-distance-between-bst-nodes

func helper(root *TreeNode, low, upper int, min *int) {
    if root == nil {
        return
    }

    diff, diff2 := root.Val - low, upper - root.Val
    if diff > diff2 {
        diff = diff2
    }
    if *min > diff && diff > 0 {
        *min = diff
    }

    helper(root.Left, low, root.Val, min)
    helper(root.Right, root.Val, upper, min)
}

func minDiffInBST(root *TreeNode) int {
    min := math.MaxInt
    helper(root, -1000000, 1000000, &min)
    return min
}
