// https://leetcode.com/problems/construct-string-from-binary-tree

func tree2str(root *TreeNode) string {
    if root == nil {
        return ""
    }

    s := strconv.Itoa(root.Val) 
    if root.Right != nil {
        s += "(" + tree2str(root.Left) + ")(" + tree2str(root.Right) + ")"
    } else if root.Left != nil {
        s += "(" + tree2str(root.Left) + ")"
    }
    return s
}
