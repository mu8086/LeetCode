// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected

type MyNode struct {
    Val int
    Left *MyNode
    Right *MyNode
    Parent *MyNode
}

func amountOfTime(root *TreeNode, start int) (minutes int) {
    queue := []*MyNode{}

    infectNeighbor := func(node *MyNode) {
        if node.Parent != nil && node.Parent.Val != 0 {
            node.Parent.Val = 0
            queue = append(queue, node.Parent)
        }
        if node.Left != nil && node.Left.Val != 0 {
            node.Left.Val = 0
            queue = append(queue, node.Left)
        }
        if node.Right != nil && node.Right.Val != 0 {
            node.Right.Val = 0
            queue = append(queue, node.Right)
        }
    }

    var dfs func(*TreeNode, *MyNode) *MyNode
    dfs = func(node *TreeNode, parent *MyNode) *MyNode {
        if node == nil {
            return nil
        }

        myNode := &MyNode{
            Val: node.Val,
            Parent: parent,
        }
        myNode.Left = dfs(node.Left, myNode)
        myNode.Right = dfs(node.Right, myNode)

        if myNode.Val == start {
            myNode.Val = 0
            queue = append(queue, myNode)
        }

        return myNode
    }

    dfs(root, nil)

    for levelSize := len(queue); levelSize > 0; levelSize = len(queue) {
        for i := 0; i < levelSize; i++ {
            infectNeighbor(queue[i])
        }
        queue = queue[levelSize:]
        minutes++
    }

    return minutes-1
}
