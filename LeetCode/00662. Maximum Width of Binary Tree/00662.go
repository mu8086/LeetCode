// https://leetcode.com/problems/maximum-width-of-binary-tree

var max int
var firstMap map[int]int // first of level

func dfs(root *TreeNode, level, idx int) {
    if root == nil {
        return
    }

    first, hasFirst := firstMap[level]
    if !hasFirst {
        firstMap[level] = idx
    } else {
        diff := idx - first + 1
        if max < diff {
            max = diff
        }
    }

    dfs(root.Left, level+1, idx*2-1)
    dfs(root.Right, level+1, idx*2)
}

func widthOfBinaryTree(root *TreeNode) int {
    max = 1
    firstMap = make(map[int]int)

    dfs(root, 0, 1)

    return max
}
/*
   1
 1   2
1 2 3 4

(L:2n-1 R:2n)
*/
