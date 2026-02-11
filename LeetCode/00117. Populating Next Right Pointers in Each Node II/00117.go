// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

func connect(root *Node) *Node {
	rightmost := make(map[int]*Node)

    var dfs func(node *Node, lv int)
    dfs = func(node *Node, lv int) {
        if node == nil {
            return
        }

        if old, exists := rightmost[lv]; exists {
            old.Next = node
        }

        rightmost[lv] = node

        dfs(node.Left, lv+1)
        dfs(node.Right, lv+1)
    }

    dfs(root, 0)

    return root
}
