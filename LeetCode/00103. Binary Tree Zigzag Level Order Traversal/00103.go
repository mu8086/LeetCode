// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

func zigzagLevelOrder(root *TreeNode) (ans [][]int) {
    queue := []*TreeNode{root}

    for l, level := len(queue), 0; l > 0; l, level = len(queue), level+1 {
        tmp := []int{}
        for i := 0; i < l; i++ {
            node := queue[i]
            if node == nil {
                continue
            }

            tmp = append(tmp, node.Val)
            queue = append(queue, node.Left)
            queue = append(queue, node.Right)
        }

        if len(tmp) > 0 {
            if (level & 1) == 1 {
                slices.Reverse(tmp)
            }
            ans = append(ans, tmp)
        }

        queue = queue[l:]
    }

    return ans
}
