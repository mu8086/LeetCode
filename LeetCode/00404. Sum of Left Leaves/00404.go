// https://leetcode.com/problems/sum-of-left-leaves

func helper(node *TreeNode, isLeft bool, sum *int) {
    if node == nil {
        return
    }

    if isLeft && node.Left == nil && node.Right == nil {
        *sum += node.Val
        return
    }

    helper(node.Left, true, sum)
    helper(node.Right, false, sum)
}

func sumOfLeftLeaves(root *TreeNode) (sum int) {
    helper(root, false, &sum)
    return sum
}
