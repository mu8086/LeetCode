// https://leetcode.com/problems/find-largest-value-in-each-tree-row

// BFS
func largestValues(root *TreeNode) []int {
    if root == nil {
        return nil
    }

    var (
        ans []int
        i, max, levelSize int

        node *TreeNode
        queue = []*TreeNode{root}
    )

    for len(queue) > 0 {
        max = queue[0].Val
        levelSize = len(queue)

        for i = 0; i < levelSize; i++ {
            node = queue[i]

            if node.Left != nil {
                queue = append(queue, node.Left)
            }
            if node.Right != nil {
                queue = append(queue, node.Right)
            }

            if max < node.Val {
                max = node.Val
            }
        }
        queue = queue[levelSize:]

        ans = append(ans, max)
    }

    return ans
}



// DFS
func dfs(root *TreeNode, level int, levelMaxMap map[int]int) {
    if root == nil {
        return
    }

    dfs(root.Left, level+1, levelMaxMap)
    dfs(root.Right, level+1, levelMaxMap)

    if levelMax, exist := levelMaxMap[level]; !exist || levelMax < root.Val {
        levelMaxMap[level] = root.Val
    }
}

func _largestValues(root *TreeNode) (ans []int) {
    levelMaxMap := make(map[int]int)    // key: level, value: levelMaxVal

    dfs(root, 0, levelMaxMap)

    for i := 0; i < 10000; i++ {
        if levelMax, exist := levelMaxMap[i]; exist {
            ans = append(ans, levelMax)
        } else {
            break
        }
    }
    return ans
}
