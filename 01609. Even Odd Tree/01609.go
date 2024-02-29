// https://leetcode.com/problems/even-odd-tree

func isEvenOddTree(root *TreeNode) bool {
    queue := []*TreeNode{root}

    for depth, levelSize := 0, len(queue); levelSize > 0; depth, levelSize = depth+1, len(queue) {
        if (depth & 1) == 0 {   // even
            for i, prev := 0, 0; i < levelSize; i++ {
                node := queue[i]

                if (node.Val & 1) == 0 {    // even value
                    return false
                }

                if prev >= node.Val {
                    return false
                }
                prev = node.Val

                if node.Left != nil {
                    queue = append(queue, node.Left)
                }
                if node.Right != nil {
                    queue = append(queue, node.Right)
                }
            }
        } else {    // odd
            for i, prev := 0, 1000001; i < levelSize; i++ {
                node := queue[i]

                if (node.Val & 1) == 1 {    // odd value
                    return false
                }

                if prev <= node.Val {
                    return false
                }
                prev = node.Val

                if node.Left != nil {
                    queue = append(queue, node.Left)
                }
                if node.Right != nil {
                    queue = append(queue, node.Right)
                }
            }
        }

        queue = queue[levelSize:]
    }

    return true
}
