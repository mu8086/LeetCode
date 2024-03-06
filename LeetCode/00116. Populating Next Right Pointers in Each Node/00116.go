// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

func connect(root *Node) *Node {
    queue := []*Node{root}
    for levelSize := len(queue); levelSize > 0; levelSize = len(queue) {
        for i := 0; i < levelSize; i++ {
            node := queue[i]
            if node == nil {
                continue
            }

            if i+1 < levelSize {
                node.Next = queue[i+1]
            }

            queue = append(queue, node.Left)
            queue = append(queue, node.Right)
        }
        queue = queue[levelSize:]
    }

    return root
}
