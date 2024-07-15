// https://leetcode.com/problems/create-binary-tree-from-descriptions

func createBinaryTree(descriptions [][]int) *TreeNode {
    m := make(map[int]*TreeNode)
    isChild := make(map[int]struct{})

    for _, d := range descriptions {
        parent, child, isLeft := d[0], d[1], d[2]
        isChild[child] = struct{}{}

        if m[parent] == nil {
            m[parent] = &TreeNode{ Val: parent }
        }

        if m[child] == nil {
            m[child] = &TreeNode{ Val: child }
        }

        if isLeft == 1 {
            m[parent].Left = m[child]
        } else {
            m[parent].Right = m[child]
        }
    }

    for _, d := range descriptions {
        if _, ok := isChild[d[0]]; !ok {
            return m[d[0]]
        }
    }

    return nil
}
