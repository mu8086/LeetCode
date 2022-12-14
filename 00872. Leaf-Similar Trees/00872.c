// https://leetcode.com/problems/leaf-similar-trees

const MAX_SIZE = 200

func getLeaf(root *TreeNode, leaf []int) []int {
    if root == nil {
        return leaf
    }

    if root.Left == nil && root.Right == nil {
        leaf = append(leaf, root.Val)
    } else {
        leaf = getLeaf(root.Left, leaf)
        leaf = getLeaf(root.Right, leaf)
    }
    return leaf
}

func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
    var leaf1, leaf2 []int
    
    leaf1 = getLeaf(root1, leaf1)
    leaf2 = getLeaf(root2, leaf2)

    if len(leaf1) != len(leaf2) {
        return false
    }

    for i := 0; i < len(leaf1); i++ {
        if leaf1[i] != leaf2[i] {
            return false
        }
    }
    return true
}
