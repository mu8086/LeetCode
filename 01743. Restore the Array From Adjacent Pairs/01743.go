// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs

type MyListNode struct {
    a, b *MyListNode
    visited bool
    val int
}

func restoreArray(pairs [][]int) (ans []int) {
    l := len(pairs)
    if l == 1 {
        return pairs[0]
    }

    head := 0
    headMap := make(map[int]bool)
    m := make(map[int]*MyListNode)

    connect := func(node0, node1 *MyListNode) {
        if node0.a == nil {
            node0.a = node1
            headMap[node0.val] = true
        } else {
            node0.b = node1
            delete(headMap, node0.val)
        }

        if node1.a == nil {
            node1.a = node0
            headMap[node1.val] = true
        } else {
            node1.b = node0
            delete(headMap, node1.val)
        }
    }

    visit := func(node *MyListNode) (next *MyListNode) {
        node.visited = true

        if node.b == nil {  // stop at another head
            return nil
        }

        if node.a.visited == false {
            return node.a
        }
        return node.b
    }

    for i := 0; i < l; i++ {
        var exists bool
        var node0, node1 *MyListNode

        if node0, exists = m[pairs[i][0]]; !exists {
            node0 = &MyListNode{val: pairs[i][0]}
            m[pairs[i][0]] = node0
        }
        if node1, exists = m[pairs[i][1]]; !exists {
            node1 = &MyListNode{val: pairs[i][1]}
            m[pairs[i][1]] = node1
        }

        connect(node0, node1)
    }

    for head = range headMap {
        break
    }

    // visit from one head to another
    m[head].visited = true
    ans = append(ans, m[head].val)
    for node := m[head].a; node != nil; node = visit(node) {
        ans = append(ans, node.val)
    }

    return ans
}
