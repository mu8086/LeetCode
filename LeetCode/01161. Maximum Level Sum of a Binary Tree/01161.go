// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

func helper(root *TreeNode, level int, levelSumMap map[int]int) {
    if root == nil {
        return
    }

    levelSumMap[level] += root.Val

    helper(root.Left, level+1, levelSumMap)
    helper(root.Right, level+1, levelSumMap)
}

func maxLevelSum(root *TreeNode) int {
    levelSumMap := make(map[int]int)

    helper(root, 1, levelSumMap)

    max := levelSumMap[1]
    maxLevel := 1
    for level, sum := range levelSumMap {
        if max < sum {
            max = sum
            maxLevel = level
        }
    }

    return maxLevel
}

func helper2(node *TreeNode, level int, sum map[int]int) {
    if node == nil {
        return
    }

    sum[level] += node.Val

    helper2(node.Left, level+1, sum)
    helper2(node.Right, level+1, sum)
}

func maxLevelSum2(root *TreeNode) int {
    sumMap := make(map[int]int)
    helper2(root, 1, sumMap)

    level := 1
    maxSum := root.Val
    for l, sum := range sumMap {
        if maxSum < sum {
            maxSum = sum
            level = l
        } else if maxSum == sum && level > l {
            level = l
        }
    }

    return level
}
