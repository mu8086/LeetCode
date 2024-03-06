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
