// https://leetcode.com/problems/search-in-a-binary-search-tree

func searchBST(root *TreeNode, val int) *TreeNode {
    if root == nil {
        return nil
    } else if root.Val == val {
        return root
    }

    l := searchBST(root.Left, val)
    r := searchBST(root.Right, val)

    if l != nil {
        return l
    }
    return r
}
