// https://leetcode.com/problems/minimum-depth-of-binary-tree

func helper(root *TreeNode, depth int, min *int) {
    if root == nil {
        return
    }

    if root.Left == nil && root.Right == nil {
        if *min > depth {
            *min = depth
        }
        return
    }

    helper(root.Left, depth+1, min)
    helper(root.Right, depth+1, min)
}

func minDepth(root *TreeNode) (min int) {
    if root == nil {
        return 0
    }

    min = 100000
    helper(root, 1, &min)
    return min
}



/* BFS */
func minDepth_BFS(root *TreeNode) int {
    if root == nil {
        return 0
    }

    queue := []*TreeNode{root}
    root.Val = 1

    for len(queue) > 0 {
        node := queue[0]
        queue = queue[1:]

        if node.Left == nil && node.Right == nil {
            return node.Val
        }

        if node.Left != nil {
            node.Left.Val = node.Val+1
            queue = append(queue, node.Left)
        }
        if node.Right != nil {
            node.Right.Val = node.Val+1
            queue = append(queue, node.Right)
        }
    }

    return 0
}
