// https://leetcode.com/problems/most-frequent-subtree-sum

func findFrequentTreeSum(root *TreeNode) (ans []int) {
    m := make(map[int]int)

    var dfs func(*TreeNode) int
    dfs = func(node *TreeNode) int {
        if node == nil {
            return 0
        }

        sum := node.Val + dfs(node.Left) + dfs(node.Right)

        m[sum]++

        return sum
    }

    dfs(root)

    maxFreq := 0
    for subtreeSum, freq := range m {
        if maxFreq < freq {
            maxFreq = freq
            ans = []int{subtreeSum}
        } else if maxFreq == freq {
            ans = append(ans, subtreeSum)
        }
    }

    return ans
}
