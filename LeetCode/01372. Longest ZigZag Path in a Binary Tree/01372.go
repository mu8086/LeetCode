// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree

var longest = 0

const (
    L = 0
    R = 1
)

func helper(root *TreeNode, from, count int) {
    if root == nil {
        if longest < count {
            longest = count
        }
        return
    }
    if from == L {
        helper(root.Left, L, 0)
        helper(root.Right, R, count+1)
    } else { // from R
        helper(root.Left, L, count+1)
        helper(root.Right, R, 0)
    }
}

func longestZigZag(root *TreeNode) int {
    helper(root.Left, L, 0)
    helper(root.Right, R, 0)
    ans := longest
    longest = 0
    return ans
}
