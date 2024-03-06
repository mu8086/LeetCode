// https://leetcode.com/problems/binary-tree-level-order-traversal-ii

func levelOrderBottom(root *TreeNode) (ans [][]int) {
    queue := []*TreeNode{root}

    for l := len(queue); l > 0; l = len(queue) {
        var tmp []int
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
            ans = append(ans, tmp)
        }

        queue = queue[l:]
    }

    slices.Reverse(ans)
    return ans
}
