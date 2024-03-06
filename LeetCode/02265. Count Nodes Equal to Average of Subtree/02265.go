// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree

func dfs(node *TreeNode, count *int) (sum, nodeSize int) {
    if node == nil {
        return
    }

    subSum, subNodeSize := dfs(node.Left, count)
    sum += subSum
    nodeSize += subNodeSize

    subSum, subNodeSize = dfs(node.Right, count)
    sum += subSum
    nodeSize += subNodeSize

    sum += node.Val
    nodeSize++
    if (sum / nodeSize) == node.Val {
        (*count)++
    }

    return sum, nodeSize
}

func averageOfSubtree(root *TreeNode) (count int) {
    dfs(root, &count)
    return count
}
