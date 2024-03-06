// https://leetcode.com/problems/clone-graph

var myMap map[int]*Node

func helper(ori *Node) *Node {
    node, exists := myMap[ori.Val]
    if exists {
        return node
    }
    
    node = &Node{
        Val: ori.Val,
    }
    myMap[ori.Val] = node
    for _, oriNei := range ori.Neighbors {
        nei := helper(oriNei)
        node.Neighbors = append(node.Neighbors, nei)
    }
    
    return node
}

func cloneGraph(ori *Node) *Node {
    if ori == nil {
        return nil
    }
    
    myMap = make(map[int]*Node)
    return helper(ori)
}
