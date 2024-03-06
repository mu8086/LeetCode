// https://leetcode.com/problems/check-completeness-of-a-binary-tree

func isCompleteTree(root *TreeNode) bool {
    if root == nil {
        return true
    }
    
    nilFlag := false
    queue := []*TreeNode{root}

    for len(queue) > 0 {
        levelSize := len(queue)
        
        for i := 0; i < levelSize; i++ {
            node := queue[0]
            queue = queue[1:]
            
            if nilFlag && node != nil {
                return false
            }
            if node == nil {
                nilFlag = true
                continue
            }
            
            queue = append(queue, node.Left)
            queue = append(queue, node.Right)
        }
    }
    
    return true
}
