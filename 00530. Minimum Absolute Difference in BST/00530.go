// https://leetcode.com/problems/minimum-absolute-difference-in-bst

func helper(root *TreeNode, parent int, min *int) {
    if root == nil {
        return 
    }
    val := root.Val
    helper(root.Left, val, min)
    helper(root.Right, val, min)
    
    diff := parent - val
    if diff < 0 {
        diff = -diff
    }
    
    if *min > diff {
        *min = diff
    }
}

func getMinimumDifference(root *TreeNode) int {
    min := 10000000
    helper(root, min, &min)
    return min
}
