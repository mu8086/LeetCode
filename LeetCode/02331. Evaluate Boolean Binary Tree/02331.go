// https://leetcode.com/problems/evaluate-boolean-binary-tree

func evaluateTree(root *TreeNode) bool {
    if root == nil {
        return false
    }

    switch root.Val {
        case 0: // False
            return false

        case 1: // True
            return true

        case 2: // OR
            return evaluateTree(root.Left) || evaluateTree(root.Right)

        case 3: // AND
            return evaluateTree(root.Left) && evaluateTree(root.Right)
    }

    return false
}
